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
    Node* q;
    int data;
    int flg;

    while(1){
        printf("整数データ入力(0で終了):");
        scanf("%d",&data);
        if(data==0) break;
        if(tail==NULL)tail=head=add_node(NULL,data);
        else tail=tail->next=add_node(NULL,data);
    }

    printf("\n=入力データ=\n");
    for(p=head;p!=NULL;p=p->next)printf("%d\n",p->data);

    printf("=データ検索=");
    while(1){
        flg=0;
        printf("\n検索するデータ(0で終了)；");
        scanf("%d",&data);
        if(data==0)break;
        if(head->data==data){
            printf("見つかりました"); flg=1;
            continue;
        }
        for(p=head;p->next!=NULL;p=p->next){
         q=p->next;
         if(q->data==data){
            printf("見つかりました"); flg=1;
            p->next = q->next;
            q->next = head;
            head = q;
            break;
         }
      }
      if(flg==0) printf("見つかりませんでした");
    }

    printf("\n＝入力データ＝\n");
    for(p=head;p!=NULL;p=p->next) printf("%d\n",p->data);

    while(head!=NULL){
        p=head->next;
        free(head);
        head=p;
    }
    return;
}