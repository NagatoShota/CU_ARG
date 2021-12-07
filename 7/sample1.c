#include <stdio.h>
#include <string.h>

//単純選択による文字列検索
int SimpleSerch(char text[],char key[]){
    int i,j,m,n;

    m = strlen(key);
    n = strlen(text);

    for(i=0;i<n-m;i++){
        for(j=0;j<m;j++){
            // 一致しなかった場合iを1つ進めて初めに戻る
            if(text[i+j] != key[j]) break;
        }
        // j=m-1まで一致した場合はiを返し終了
        if(j==m) return i;
    }
    return -1;
}

int main(){
    char text[] = "She sells seashells.";
    char key[] = "sea";
    int rc;

    printf("テキスト: %s\n",text);
    printf("キーワード: %s\n",key);

    rc = SimpleSerch(text,key);

    printf("検索結果 :");
    if(rc!=-1){
        printf("キーワードは%d文字目に検索されました\n",rc+1);
    }else{
        printf("キーワードは検索されませんでした\n");
    }

    return 0;
}