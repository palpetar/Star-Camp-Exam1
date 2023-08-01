#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Car{
    char model[20];
    uint8_t maxspeed;
    double price;
} Car;

int cmp_model_asc(const void *a, const void *b){
    Car c1 = *(Car*)a;
    Car c2 = *(Car*)b;
    return strcmp(c1.model, c2.model);
}

int cmp_model_des(const void *a, const void *b){
    Car c1 = *(Car*)a;
    Car c2 = *(Car*)b;
    return -(strcmp(c1.model, c2.model));
}

int cmp_speed_asc(const void *a, const void *b){
    Car c1 = *(Car*)a;
    Car c2 = *(Car*)b;
    return c1.maxspeed > c2.maxspeed;
}

int cmp_speed_des(const void *a, const void *b){
    Car c1 = *(Car*)a;
    Car c2 = *(Car*)b;
    return !(c1.maxspeed > c2.maxspeed);
}

int cmp_price_asc(const void *a, const void *b){
    Car c1 = *(Car*)a;
    Car c2 = *(Car*)b;
    return c1.price > c2.price ? 1 : -1;
}

int cmp_price_des(const void *a, const void *b){
    Car c1 = *(Car*)a;
    Car c2 = *(Car*)b;
    return c1.price > c2.price ? -1 : 1;
}

void print_elems(Car *arr){
    for(int i = 0; i < 10; i++){
        printf("Model: %s\t\tMaxSpeed: %d\t\tPrice:%.2lf\n", arr -> model, arr -> maxspeed, arr -> price);
        arr++;
    }
    printf("\n");
}

int (*getComparator(int n))(const void*, const void*){
    switch(n){
        case 1:
            return cmp_model_asc;
            break;
        case 2:
            return cmp_model_des;
            break;
        case 3:
            return cmp_speed_asc;
            break;
        case 4:
            return cmp_speed_des;
            break;
        case 5:
            return cmp_price_asc;
            break;
        case 6:
            return cmp_price_des;
            break;
        
    }
}

int main(void){

    srand(time(NULL));
    Car *arr = malloc(sizeof(Car) * 10);
    const char POSSIBLE_CHARS[] = "abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 4 + rand()%6; j++){
            arr[i].model[j] = POSSIBLE_CHARS[rand()%strlen(POSSIBLE_CHARS)];
        }
        arr[i].maxspeed = 100 + rand()%200;
        arr[i].price = (100000 + rand()%9900000)/100;
    }
    print_elems(arr);
    printf("Which method should we sort? (1-6)");
    int command;
    scanf("%d", &command);
    qsort(arr, 10, sizeof(Car), getComparator(command));
    print_elems(arr);
    return 0;
}