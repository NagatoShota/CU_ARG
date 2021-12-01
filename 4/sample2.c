#include <stdio.h>

// コムソートによる並び替え
void CombSort(int x[], int n){
    int i,j,tmp,gap,flg=1;

    gap=n;
    // gapが1かつflgが0になったらループ終了
    while(gap > 1 || flg == 1){
        gap=gap * 10/13;
        // gapが1未満の場合1にする
        if(gap<1) gap=1;
        flg = 0;

        for(i=0;i+gap<n;i++){
            if(x[i]>x[i+gap]) {
                tmp = x[i];
                x[i] = x[i+gap];
                x[i+gap] = tmp;
                // 交換があるとフラグを1にする
                flg=1;
            }
        }
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
 
    //BubbleSort(data,8);  
    CombSort(data,8);
 
    printf("\n並べ替え後\n");
    for(i=0;i<8;i++) printf("%d\t",data[i]);
    printf("\n");
 
    return;
}