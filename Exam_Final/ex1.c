#include <stdio.h>
#include <inttypes.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define ITEMS_COUNT 5


typedef struct BankAccount {
    uint16_t number;
    char name[100];
    double balance;
    char currency[4];
} BankAccount;

typedef struct node_t {
    BankAccount val;
    struct node_t *next;
} node_t;

typedef struct LinkedList {
    node_t *head;
} LinkedList;

double totalBalance(node_t* head){
    double sum = 0;
    for(int i = 0; i < ITEMS_COUNT; i++){
        sum += head -> val.balance;
        head = head -> next;
    }
    return sum;
}

node_t * maxBalance(node_t* head){
    double biggest = 0;
    node_t *biggest_node;
    for(int i = 0; i < ITEMS_COUNT; i++){
        if(head -> val.balance > biggest){
            biggest = head -> val.balance;
            biggest_node = head;
        }
    }
    return biggest_node;
}

void print_list(node_t* head){
    for(int i = 0; i < ITEMS_COUNT; i++){
        printf("Number: %d\t\tName: %s\t\tBalance: %.2lf\t\tCurrency: %s\n", head -> val.number, head -> val.name, head -> val.balance, head -> val.currency);
    }
}

void add_elems(LinkedList *linkedList){

    const char* ALLOWED_CURRENCIES[] = {"EUR", "BGN", "USD"};
    const char POSSIBLE_CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    for(int i = 0; i < ITEMS_COUNT; i++){
        node_t *new_node = malloc(sizeof(node_t));
        new_node -> next = NULL;
        new_node -> val.number = i;
        new_node -> val.name[0] = POSSIBLE_CHARS[rand()%25];
        int counter = 1;
        for(int j = 0; j < 2 + rand()%3; j++){
            for(int z = 1; z < 1 + rand()%19; z++){
                new_node ->val.name[counter++] = POSSIBLE_CHARS[rand()%53];
            }
            new_node -> val.name[counter++] = ' ';
        }
        new_node -> val.name[counter] = '\0';
        new_node -> val.balance = (rand()%10000000) / 100;
        strcpy(new_node -> val.currency, ALLOWED_CURRENCIES[rand()%3]);
        
        if(linkedList -> head == NULL){
            linkedList -> head = new_node;
        } else{
            while(linkedList -> head -> next){
                linkedList -> head = linkedList -> head -> next;
            }
            linkedList -> head -> next = new_node;
        }
    }
}

int main(void){
    

    LinkedList *linkedList = (LinkedList*)malloc(sizeof(LinkedList));
    if(!linkedList){ // If NULL pointer
        perror("Could not malloc\n");
        exit(-1);
    }
    linkedList -> head = NULL;
    add_elems(linkedList);
    print_list(linkedList -> head);
    return 0;
}