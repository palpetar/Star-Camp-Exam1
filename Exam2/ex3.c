#include <stdio.h>
#include <string.h>


int contains_char(const char *str, char c){
    while(*str != '\0'){
        if(*str == c){
            return 0;
        }
        str++;
    }
    return -1;
}

void convert_add(char *str, double *sum){
    if(contains_char(str, '.') == 0){
        *sum += strtof(str);
    } else if(contains_char(str, 'x') == 0 || contains_char(str, 'X') == 0){
        str += 2;
        *sum += strtoul(str, NULL, 16);
    } else {
        *sum += atoi(str);
    }
}

int main(int argc, char *argv[]){
    double sum = 0;
    for (int i = 1; i < argc; i++) {
        convert_add(argv[i], &sum);
    }
    printf("%.2lf", sum);
    return 0;

}