#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include <inttypes.h>
#include <semaphore.h>
#include <sys/stat.h>


int main(int argc, char* argv[]){


    if(argc <= 1){
        perror("Not enough arguments");
    }

    int pid;
    int fd[argc][2];
    for(int i = 1; i < argc; i++){
        pid = fork();
        if(pid == 0){
            char *filename = argv[i];
            FILE *file = fopen(filename, "r");
            if(file == NULL){
                perror("Error opening file");
                exit(-1);
            }

            struct stat file_info;
            stat(filename, &file_info);
            unsigned int file_size;
            file_size = file_info.st_size;

            uint64_t *numbers = malloc(file_size);
            
            fread(numbers, sizeof(uint64_t), file_size, file);
            uint64_t sum_local = 0;
            for(size_t i = 0; i < file_size / sizeof(uint64_t); i++){
                sum_local += numbers[i];
            }
            write(fd[i][1], &sum_local, sizeof(sum_local));
            fclose(file);
        }
    }
    if(pid != 0){
        uint64_t sum_total = 0;
        uint64_t sum_current;
        for(int i = 1; i < argc; i++){
            read(fd[i][0], &sum_current, sizeof(sum_current));
            sum_total += sum_current;
        }

        printf("Total sum: %lu\n", sum_total);
    }
}