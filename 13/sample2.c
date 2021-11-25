#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10
int queue[MAX_NUM];
int first=0;
int last=0;

char menu[4][20]={"","カレー","牛丼","ラーメン"};

// void enqueue(int data){
//     if((last+1)%MAX_NUM==first){
//         printf("キューは満杯で追加できません\n");
//         return;
//     }
//     queue[last]=data;
//     last=(last+1)%MAX_NUM;
//     return;
// }

// int dequeue(void){
//     int ret;
//     if(first==last){
//         printf("キューにデータがありません\n");
//         return -1;
//     }
//     ret=queue[first];
//     first=(first+1)%MAX_NUM;
//     return ret;
// }

// int firstdata_queue(void){
//     if(first==last) return -1;
//     else return queue[first];
// }

// void print_queue(){
//     int i;
//     for(i=first;i!=last;i=(i+1)%MAX_NUM){
//         // printf("%d\n",queue[i]);
//     }
//     return;
// }

typedef struct node{
   struct node* next;
   int data;
}Node;
 
Node* head=NULL;
Node* tail=NULL;
 
void enqueue(int x)
{
   Node* p;
   p = (Node*)malloc(sizeof(Node));
   p->next = NULL;
   p->data = x;
   if(tail==NULL) head=p;
   else tail->next=p;
   tail=p;
   return;
}
 
int dequeue(void)
{
   int x;
   Node* p;
   if(head==NULL){
      printf("キューにデータがありません");
      return -1;
   }
   p=head;
   x=p->data;
   head=p->next;
   free(p);
   return x;
}
 
int firstdata_queue(void)
{
   if(head==NULL) return -1;
   else return head->data;
}
 
void print_queue()
{
   Node* p;
   for( p=head ; p!=NULL ; p=p->next ){
      printf("%s\n",menu[p->data]);
   }
   return;
}


void main(void)
{
   int rc,data;
 
   while(1){
      printf("\nカレー:1 牛丼:2 ラーメン:3 出来上がり:0 キュー表示:-1\n");
      printf("注文を入力 : ");
      scanf("%d",&data);
      switch(data){
         case -1:
            printf("\n＝調理待ちリスト＝\n");
            print_queue();
            break;
         case 0:
            rc=dequeue();
            if(rc != -1) printf("%sできあがりですね\n",menu[rc]);
            rc=firstdata_queue();
            if(rc != -1) printf("次は%sです\n",menu[rc]);
            break;
         case 1:
         case 2:
         case 3:
            enqueue(data);
            printf("%s の注文を登録しました\n",menu[data]);
            break;
         default:
            printf("終了します\n"); return;
      }
   }
   return;
}