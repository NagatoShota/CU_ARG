#include <stdio.h>
#include <stdlib.h>

void main(void){
    int* data;
    int i,n;

    printf("何件のデータを入力しますか:");
    scanf("%d",&n);
    data=(int*)malloc(sizeof(int)*n);

    for(i=0;i<n;i++){
        printf("整数データ入力:");
        scanf("%d",&data[i]);
    }

    printf("\n=入力データ=\n");
    for(i=0;i<n;i++) printf("%d\n",data[i]);

    free(data);
    return;
}