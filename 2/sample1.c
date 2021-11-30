#include <stdio.h>
#define N 8  //データ件数


// 線形探索による検索プログラム
// 検索対象データの配列x,検索対象データの要素数n,検索対象データy
int LinearSearch(int x[], int n, int y){
    int i=0;
    while(i<n){
        if(x[i]==y) return i;
        else i++;
    }
    // 見つからなければ-1を返して終了
    return -1;
}

// 番人を使用した検索プログラム
int SentinelSearch(int x[], int n, int y){
    int i=0;
    // 配列の最後尾に番人yを追加
    x[n]=y;
    while(1){
        if(x[i]==y) break;
        else i++;
    }
    // iがnより小さいか（番人ではないか確認）
    if(i<n) return i;
    return -1;
}

void main(){
    int data[N+1] = {11,22,33,44,55,66,77,88};
    // 検索目標target,関数の戻り値を格納するrc
    int target,rc;

    printf("目標データを入力:");
    scanf("%d",&target);
    rc = LinearSearch(data, N, target);
    rc = SentinelSearch(data, N, target);
    if(rc == -1) printf("見つかりません\n");
    else printf("要素番号 %dのデータです\n",rc);

    return;
}