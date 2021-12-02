#include <stdio.h>

//基本挿入法による並び替え
void InsertionSort(int x[], int n){
    int i,j,tmp;

    for(j=1;j<n;j++){
        // tmpに格納しておく
        tmp = x[j];
        for(i=j-1;i>=0;i--){
            // tmpより大きければ一つ右に(x[j]の位置)
            if(x[i]>tmp) x[i+1] = x[i];
            else break;
        }
        // x[j]の値を開いた位置に
        x[i+1] = tmp;
    }
    return;
}

void main()
{
   int i;
   int data[8]={3,2,8,5,7,1,6,4};
 
   printf("\n並べ替え前\n");
   for(i=0;i<8;i++)printf("%d\t",data[i]);
   printf("\n");
 
   InsertionSort(data,8);
 
   printf("\n並べ替え後\n");
   for(i=0;i<8;i++)printf("%d\t",data[i]);
   printf("\n");
 
   return;
}