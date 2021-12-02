#include <stdio.h>
int COMPARE_COUNT;
int MOVE_COUNT;


// セルソートによる並び替え
void ShellSort(int x[],int n){
    int i,j,k,tmp,gap;

    gap=1;
    while(n>gap) gap = gap*3 + 1;
    gap = (gap-1)/3;
    while(gap>0){
        for(k=0;k<gap;k++){
            for(j=k+gap;j<n;j=j+gap){
                tmp = x[j];MOVE_COUNT++;
                for(i=j-gap;i>=0;i=i-gap){
                    COMPARE_COUNT++;
                    if(x[i]>tmp) {x[i+gap] = x[i];MOVE_COUNT++;}
                    else break;
                }
                x[i+gap] = tmp;MOVE_COUNT++;
            }
        }
        gap = (gap-1)/3;
    }
    return;
}


void main()
{
   int i;
   int data[8]={3,2,8,5,7,1,6,4};
    
   printf("\n並べ替え前\n");
   for(i=0;i<8;i++) printf("%d\t",data[i]);
   printf("\n");
 
   printf("\n=シェルソート=\n");
   COMPARE_COUNT=MOVE_COUNT=0;
   ShellSort(data,8);
   printf("比較%d回、移動%d回\n",COMPARE_COUNT,MOVE_COUNT);
 
   printf("\n並べ替え後\n");
   for(i=0;i<8;i++) printf("%d\t",data[i]);
   printf("\n");
 
   return;
}