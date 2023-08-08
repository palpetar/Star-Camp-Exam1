#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Product
{
     double old_price; // 8
     double new_price; // 8
     unsigned int id; // 4
     char product_type; // 1
     
     char product_name[11];  
} Product;




void swap(Product *a, Product *b){
    Product temp = *a;
    *a = *b;
    *b = temp;
}

int cmpPrice(Product *a, Product *b){
    double diff1 = a->new_price - a->old_price;
    double diff2 = b->new_price - b->old_price;
    
    if(diff1 - diff2 <= 0.1){
        return 0;
    } else if(diff1 > diff2){
        return -1;
    } else {
        return 1;
    } 
}

int cmpType(Product *a, Product *b){
    char type1 = a -> product_type;
    char type2 = b -> product_type;

    if(type1 == type2){
        return 0;
    } else if(type1 > type2){
        return -1;
    } else {
        return 1;
    }
}

int cmpName(Product *a, Product *b){
    char name1 = a -> product_name[0];
    char name2 = b -> product_name[0];

    if(name1 == name2){
        return 0;
    } else if(name1 > name2){
        return -1;
    } else {
        return 1;
    }
}

int cmpID(Product *a, Product *b){
    int id1 = a -> id;
    int id2 = b -> id;

    return id1 > id2 ? 1 : -1;
}

void sort(Product *arr){
    for(int i = 0; i < 40; i++){
        for(int j = 0; j < 40 - i; j++){
            if(cmpPrice(&arr[j], &arr[j + 1]) == 1){
                swap(&arr[j], &arr[j + 1]);
            } else if(cmpPrice(&arr[j], &arr[j + 1]) == 0){
                if(cmpType(&arr[j], &arr[j + 1]) == 1){
                    swap(&arr[j], &arr[j + 1]);
                } else if(cmpType(&arr[j], &arr[j + 1]) == 0){
                    if(cmpName(&arr[j], &arr[j + 1]) == -1){
                        swap(&arr[j], &arr[j + 1]);
                    } else if(cmpName(&arr[j], &arr[j + 1]) == 0){
                        if(cmpID(&arr[j], &arr[j+1]) == -1){
                            swap(&arr[j], &arr[j + 1]);
                        }
                    }
                }
            }
        }
    }
}

int main(void){

    Product arr[40];

    srand(time(NULL));
    const char TYPES_ALLOWED[] = "ABCD";
    const char *POSSIBLE_NAMES[] = {"Chair", "Table", "Computer", "Sink", "Microphone"};

    for(int i = 0; i < 40; i++){
        arr[i].old_price = (499 + rand()%9546) / 100;
        arr[i].new_price = (499 + rand()%9546) / 100;
        arr[i].id = i;
        arr[i].product_type = TYPES_ALLOWED[rand()%strlen(TYPES_ALLOWED)];
        strcpy(arr[i].product_name, POSSIBLE_NAMES[rand()%5]);
    }
    printf("Before sort:\n\n");
    for (int i = 0; i < 40; i++) {
        printf("ID: %d, Type: %c, Name: %s, Old Price: %.2lf, New Price: %.2lf\n", arr[i].id, arr[i].product_type, arr[i].product_name, arr[i].old_price, arr[i].new_price);
    }
    printf("\nAfter sort:\n\n");
    sort(arr);
    for (int i = 0; i < 40; i++) {
        printf("ID: %d, Type: %c, Name: %s, Old Price: %.2lf, New Price: %.2lf\n", arr[i].id, arr[i].product_type, arr[i].product_name, arr[i].old_price, arr[i].new_price);
    }
}