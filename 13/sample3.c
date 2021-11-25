#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* next;
    int data;
}Node;

Node* head=NULL;

void push(int x){
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->next = head;
    head=p;
    return;
}

int pop(void){
    int x;
    Node* p;
    if(head==NULL){
        printf("スタックにデータがありません");
        return -1;
    }
    p=head;
    x=p->data;
    head=p->next;
    free(p);
    return x;
}