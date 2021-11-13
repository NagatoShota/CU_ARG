#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* next;
    int data;
}Node;

Node* add_node(Node* next, int data){
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->next = next;
    p->data = data;
    return p;
}

void main(void){
    Node* head=NULL;
    Node* tail=NULL;
    Node* p;
    int data;

    while(1){
        printf("整数データ入力(0で終了):");
        scanf("%d",&data);
        if(data==0) break;
        if(tail==NULL)tail=head=add_node(NULL,data);
        else tail=tail->next=add_node(NULL,data);
    }

    printf("\n=入力データ=\n");
    for(p=head;p!=NULL;p=p->next)printf("%d\n",p->data);

    while(head!=NULL){
        p=head->next;
        free(head);
        head=p;
    }
    return;
}