#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_even(char *arr, char c, int i){
    switch(c){
        case '0':
            arr[i] = '!';
            break;
        case '1':
            arr[i] = '#';
            break;
        case '2':
            arr[i] = '/';
            break;
        case '3':
            arr[i] = '-';
            break;
        case '4':
            arr[i] = '=';
            break;
        case '5':
            arr[i] = '\'';
            break;
        case '6':
            arr[i] = '\\';
            break;
        case '7':
            arr[i] = '>';
            break;
        case '8':
            arr[i] = '.';
            break;
        case '9':
            arr[i] = ',';
            break;
    }
}

void add_odd(char *arr, char c, int i){
    arr[i] = c + ('A' - '0');
}

void print_elems(char *s){
    while(*s != 0){
        printf("%c", *s);
        s++;
    }
    printf("\n");
}

int main(void){

    char *input[500];
    scanf("%s", input);
    char *arr = calloc(500, sizeof(char));


    int counter = 0;
    while(*input != '\0'){
        if(counter % 2 == 0){
            add_even(arr, *input, counter);
        } else{
            add_odd(arr, *input, counter);
        }
        counter++;
        input++;
    }
    arr[counter] = 0;
    print_elems(input);
    print_elems(arr);

    free(arr);
    return 0;
}