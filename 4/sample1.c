#include <stdio.h>


// バブルソートによる並び替え
void BubbleSort(int x[],int n){
    int i, j, tmp, flg=1;

    for (j=n-1;flg==1;j--){
        flg=0;
        for(i=0;i<j;i++){
            if(x[i]>x[i+1]){
                tmp = x[i];
                x[i] = x[i+1];
                x[i+1] = tmp;
                flg=1;
            }
        }
    }
    return;

}

void main(){
    int i;
    int data[8]={3,2,8,5,7,1,6,4};

    printf("\n並び替え前\n");
    for(i=0;i<8;i++) printf("%d\t",data[i]);
    printf("\n");

    BubbleSort(data,8);

    printf("\n並び替え後\n");
    for(i=0;i<8;i++) printf("%d\t",data[i]);
    printf("\n");

    return;
}