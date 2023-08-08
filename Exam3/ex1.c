#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void hex_dump(FILE *file){
    char current;
    while((current = getc(file)) != EOF){
        printf("%02x ", current);
    }
    printf("\n");
}

void binary_dump(FILE *file){
    
}

int main(int argc, char* argv[]){

    FILE *file = fopen(argv[1], "r");

    if(strcmp(argv[2], "-H") == 0){
        hex_dump(file);
    }
    
    if(strcmp(argv[2], "-B") == 0){
        binary_dump(file);
    }

    return 0;
}