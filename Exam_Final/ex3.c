#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <inttypes.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/stat.h>
#include <string.h>

typedef struct arg_t{
    int index;
    int *arr;
    int size;
    char *filename;
} arg_t;

//pthread_mutex_t lock;

void *thread_fun(void *args){
    arg_t data = *(arg_t*)args;
    double sum = 0;
    for(int i = 0; i < data.size; i++){
        sum += data.arr[i];
    }
    double average = sum / data.size;

    FILE *file = fopen(data.filename, "r");
    if(file != NULL){
        perror("File already exists");
        exit(-1);
    }
    file = fopen(data.filename, "w");

    char *result = "ROW ";
    char buf[50];
    snprintf(buf, 50, "%d", data.index);
    strcat(result, buf);
    strcat(result, " ");
    snprintf(buf, 50, "%.2lf", average);
    strcat(result, buf);

    fputs(result, file);
    fputs("\n", file);

    fclose(file);

}

int main(void){

    int n, m;

/*     if(pthread_mutex_init(&lock, NULL)) {
        perror("Could not init mutex");
    } */

    scanf("%d %d", &n, &m);

    arg_t *arguments = malloc(sizeof(arg_t) * n);
    for(int i = 0; i < n ; i++){
        arg_t *current_arg = malloc(sizeof(arg_t));
        char buf[256];
        fgets(buf, 256, stdin);
        const char *delim = " ";
        char *token = strtok(buf, delim);
        
        int counter = 0;
        while(token != NULL){
            if(atoi(token) != 0 && atoi(token) != i) {
                //printf("%s", token);
                current_arg -> arr[counter++] = atoi(token);
            }
        }
        current_arg -> index = i;
        current_arg -> size = counter;
        arguments[i] = *current_arg;
    }

    char *filename;
    scanf("%s", filename);

    for(int i = 0; i < m; i++){
        arguments[i].filename = filename;
    }
    
    pthread_t threads[n];
    for(int i = 0; i < n; i++){
        if(pthread_create(threads + i, NULL, thread_fun, arguments + i) == -1){
            perror("Could not create thread");
            exit(-1);
        }
    }

    for(int i = 0; i < n; i++){
        pthread_join(*(threads + i), NULL);
    }

    return 0;
}