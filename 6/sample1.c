#include <stdio.h>

void SelectionSort(int x[], int n){
    int max_id,tmp;

    for (int j=7;j>=1;j--){
        max_id = 0;
        for(int i=1;i<=j;i++){
            if(x[max_id]<x[i]) max_id = i;
        }
        tmp = x[j];
        x[j] = x[max_id];
        x[max_id] = tmp;
    }
    return;
}