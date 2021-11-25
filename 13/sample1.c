#include <stdio.h>
#include <stdlib.h>


#define SMALL  1
#define MEDIUM 2
#define LARGE  3
 
#define OK    0
#define ERROR 1

// #define MAX_NUM 10


// int stack[MAX_NUM];
// int num;

// void push(int data){
//     if(num==MAX_NUM) {
//         printf("これ以上詰めません");
//         return;
//     }
//     stack[num] = data;
//     num++;
//     return;
// }

// int pop(void){
//     if(num==0){
//         printf("スタックにデータがありません");
//         return 0;
//     }
//     num--;
//     return stack[num];
// }

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

int check(char* str){
    int i;
    // num=0;
    head=NULL;

    for(i=0;str[i]!='\0';i++){
        switch (str[i])
        {
        case '(':
            push(SMALL); break;
        case '{':
            push(MEDIUM); break;
        case '[':
            push(LARGE); break;
        case ')':
            if(pop()==SMALL) break;
            else return ERROR;
        case '}':
            if(pop()==MEDIUM) break;
            else return ERROR;
        case ']':
            if(pop()==LARGE) break;
            else return ERROR;
        }
    }
    // if(num==0) return OK;
    if(head==NULL) return OK;
    else return ERROR;
}

void main(void){
    char str[100];

    printf("式を入力:");
    scanf("%s",str);

if(check(str)==OK) printf("カッコの対応は取れています\n");
else printf("カッコの対応は取れていません\n");

return;
}

