#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct S{
    char *values;
    size_t current;
} S;

S init_array(){
    S arr;
    arr.values = calloc(500, sizeof(S));
    arr.current = 0;
    return arr;
    printf("init\n");
}

void add(S *arr, char c){
    if(arr -> current % 2 == 0){
        arr -> values[arr -> current] = c + ('A' - '0');
    } else {
        switch(c){
            case '0':
                arr -> values[arr -> current] = '!';
                break;
            case '1':
                arr -> values[arr -> current] = '#';
                break;
            case '2':
                arr -> values[arr -> current] = '/';
                break;
            case '3':
                arr -> values[arr -> current] = '-';
                break;
            case '4':
                arr -> values[arr -> current] = '=';
                break;
            case '5':
                arr -> values[arr -> current] = '\'';
                break;
            case '6':
                arr -> values[arr -> current] = '\\';
                break;
            case '7':
                arr -> values[arr -> current] = '>';
                break;
            case '8':
                arr -> values[arr -> current] = '.';
                break;
            case '9':
                arr -> values[arr -> current] = ',';
                break;
        }
    }
    arr -> current++;
}

void init_string(S *arr, char *input){
    for(size_t i = 0; i < strlen(input); i++){
        add(arr, input[i]);
    }
}

void print_elems(S arr){
    for(size_t i = 0; i < arr.current; i++){
        printf("%c", arr.values[i]);
    }
    printf("\n");
}

int main(void){

    S arr = init_array();
    char *s = "testing";
    init_string(&arr, s);
    print_elems(arr);

    return 0;
}