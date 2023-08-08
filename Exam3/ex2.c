#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* insertAfter(Node *cll, int skipCount, int newElem){
    for(int i = 0; i < skipCount; i++){
        cll = cll -> next;
    }
    Node *temp_node = cll -> next;
    Node *new_node = malloc(sizeof(Node));
    new_node -> data = newElem;
    cll -> next = new_node;
    new_node -> next = temp_node;

    return new_node;
}

void print(Node *cll){
    Node *current = cll;
    
    do {
        printf("%d\n", current -> data);
        current = current -> next;
    } while(current != cll);
    printf("\n");    
}

void free_all(Node *cll) {

    Node *current = cll;
    Node *next_node;

    do {
        next_node = current->next;
        free(current);
        current = next_node;
    } while (current != cll);
}

int main(void){

    Node *head = malloc(sizeof(Node));
    head->data = 1;
    Node *node2 = malloc(sizeof(Node));
    node2->data = 2;
    Node *node3 = malloc(sizeof(Node));
    node3->data = 3;
    head->next = node2;
    node2->next = node3;
    node3->next = head;


    print(head);

    Node *new_head = insertAfter(head, 1, 10);
    print(new_head);
    
    print(head);

    free_all(head);
    
    return 0;
}
