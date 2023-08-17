#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <inttypes.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/stat.h>

pthread_mutex_t lock;

uint64_t sum = 0;

void *thread_fun(void *args){
    uint64_t sum_local = 0;
    char *filename = (char*)args;
    FILE *file = fopen(filename, "r");

    unsigned int file_size;
    struct stat file_info;
    stat(filename, &file_info);
    file_size = file_info.st_size;

    uint64_t *numbers = malloc(file_size);
    fread(numbers, sizeof(uint64_t), file_size, file);

    for(size_t i = 0; i < file_size / sizeof(uint64_t); i++){
        sum_local += numbers[i];
    }

    pthread_mutex_lock(&lock);
    sum += sum_local;
    pthread_mutex_unlock(&lock);
    fclose(file);
    free(numbers);
}

int main(int argc, char* argv[]){


    if(argc <= 1){
        perror("Not enough arguments");
    }

    if(pthread_mutex_init(&lock, NULL)) {
        perror("Could not init mutex");
    }

    pthread_t threads[argc];

    for(int i = 1; i < argc; i++){
        if(pthread_create(&threads[i - 1], NULL, thread_fun, argv[i]) == -1){
            perror("Could not create thread");
            exit(-1);
        }
    }

    for(int i = 1; i < argc; i++){
        pthread_join(threads[i - 1], NULL);
    }
    
    printf("Total sum: %lu", sum);

    pthread_mutex_destroy(&lock);    
}