#include <stdio.h>
#define N 8 //データ件数


// 二分探索による検索関数
int BinarySearch(int x[], int n, int y){
    int min,mid,max;
    min=0;
    max=n-1;
    
    while(min<=max){
        mid = (min + max)/2;
        if(x[mid]<y) min = mid + 1;
        else if(x[mid]>y) max = mid - 1;
        else return mid;
    }
    return -1;
}

void main(){
    int data[N] = {11,22,33,44,55,66,77,88};
    int target,rc;

    printf("目標データを入力:");
    scanf("%d",&target);

    printf("\n二分探索\n");
    rc = BinarySearch(data,N,target);
    if(rc == -1)printf("見つかりません\n");
    else printf("要素番号%dのデータです\n",rc);

    return;
}