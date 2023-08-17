#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


int main(int argc, char* argv[]){

    if(argc != 3){
        perror("Not enough arguments");
        exit(-1);
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "w");
    size_t n = atoi(argv[2]);

    if(file == NULL){
        perror("File is NULL pointer");
        exit(-1);
    }

    for(uint64_t i = 0; i < n; i++){
        fwrite(&i, sizeof(i), 1, file);
    }


    fclose(file);

}