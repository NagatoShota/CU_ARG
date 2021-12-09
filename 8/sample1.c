#include <stdio.h>
#include <string.h>

//スキップ表の作成
//unsignedで文字コードを正の整数とみなし要素番号として使えるようにしている
int BMSearch(unsigned char text[], unsigned char key[]){
    int table[256];
    int nt,nk,i,t,k;

    nt = strlen(text);
    nk = strlen(key);

    //スキップ数を全てキーワードの文字数に初期化
    for(i=0;i<256;i++) table[i]=nk;
    //キーワードに含まれる文字については正しいスキップ数で上書き
    for(i=0;i<nk;i++) table[key[i]]=nk-i-1;

    //検索開始
    // 比較位置の要素番号をキーワード末尾の要素番号で初期化
    t = k = nk-1;
    while(t<nt){
        // 一致した場合
        if(text[t] == key[k]){
            // k=0まで一致した場合はtを返し終了
            if(k==0) return t;
            //次の比較位置を左隣とするようt,k共に1小さくする
            t--;k--;
        }else {
            //スキップ数が比較位置の右端からの距離 nk-1-kより少ない場合、次の比較位置はキーワード右端の右隣nk-kへ
            if(table[text[t]] <= nk-1-k) t = t+nk-k;
            // テキスト上の比較位置は右へスキップさせるようスキップ数だけ大きくする
            else t = t + table[text[t]];
            // キーワード上の次の比較位置は右端のnk-1とする
            k = nk - 1;
        }
    }
    return -1;
}

int main(){
    char text[] = "She sells seashells by the seashore.";
    char key[64];
    int rc;

    printf("テキスト：%s\n",text);
    printf("キーワード：");
    scanf("%s",key);

    rc = BMSearch(text, key);

    printf("検索結果 :");
    if(rc != -1) {
        printf("キーワードは%d文字目に検索されました\n",rc+1);
    }else {
        printf("キーワードは検索されませんでした\n");
    }
    return 0;
}