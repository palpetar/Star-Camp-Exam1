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
            head = head -> next;
        }
    }
    return biggest_node;
}

void print_list(node_t* head){
    for(int i = 0; i < ITEMS_COUNT; i++){
        printf("Number: %d\nName: %s\nBalance: %.2lf\nCurrency: %s\n\n", head -> val.number, head -> val.name, head -> val.balance, head -> val.currency);
        head = head -> next;
    }
}

void push_back(BankAccount new_data, node_t **head) {
    // *head - Node*
    // **head - Node
    // Allocate dynamic memory for new node
    node_t *new_last_node = malloc(sizeof(node_t));
    if(!new_last_node) {
        perror("Could not malloc\n");
        exit(-1);
    }
    new_last_node->val = new_data;
    new_last_node->next = NULL;

    // Empty linked list
    if(*head == NULL) {
        *head = new_last_node;
        return;
    }

    // Get address of first node
    node_t *cur_node = *head;
    while(cur_node->next != NULL) {
        cur_node= cur_node->next;
    }
    // After while loop - cur_node keeps address of last node
    cur_node->next = new_last_node;
}

void add_elems(LinkedList *linkedList){

    const char* ALLOWED_CURRENCIES[] = {"EUR", "BGN", "USD"};
    const char POSSIBLE_CHARS[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    srand(time(NULL));
    for(int i = 0; i < ITEMS_COUNT; i++){
        BankAccount new_data;

        new_data.number = i;
        new_data.name[0] = POSSIBLE_CHARS[rand()%25];
        int counter = 1;
        for(int j = 0; j < 2 + rand()%3; j++){
            for(int z = 1; z < 1 + rand()%19; z++){
                new_data.name[counter++] = POSSIBLE_CHARS[rand()%53];
            }
            new_data.name[counter++] = ' ';
        }
        new_data.name[counter] = '\0';
        new_data.balance = (rand()%10000000) / 100;
        strcpy(new_data.currency, ALLOWED_CURRENCIES[rand()%3]);
        
        push_back(new_data, &(linkedList -> head));
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

    printf("Total balance: %.2lf\n", totalBalance(linkedList -> head));

    node_t *biggest = maxBalance(linkedList -> head);
    printf("\nBiggest Balance: \nNumber: %d\nName: %s\nBalance: %.2lf\nCurrency: %s\n\n", biggest -> val.number, biggest -> val.name, biggest -> val.balance, biggest -> val.currency);

    return 0;
}