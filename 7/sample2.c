#include <stdio.h>
#include <string.h>

// KMP法による文字列検索
int KMPSearch(char text[], char key[]){
    int i,j,k,l,m,n;
    int table[64];

    m=strlen(key);
    n=strlen(text);

    //表の作成
    table[0]=table[1]=0;
    k=1;l=0;
    while(k<m){
        if(key[k]==key[l]){
            k++;l++;
            table[k]=l;
        }else if(l>0){
            l=table[l];
        }else{
            k++;
            table[k]=0;
        }
    }

    // 表の表示
    printf("作成した表:");
    for(i=0;i<m;i++) printf("%d",table[i]);
    printf("\n");

    //検索開始
    i=0;j=0;
    while(i<=n-m){
        if(text[i+j]==key[j]){
            j++;
            if(j==m)return i;
        }else{
            if(j==0)i++;
            else i=i+j-table[j];
            j=table[j];
        }
    }
    return -1;
}

int main()
{
  char text[]="ababcababd";
  char key[]="ababd";
  int rc;
 
  printf("テキスト  ：%s\n",text);
  printf("キーワード：%s\n",key);
 
  rc = KMPSearch(text,key);
 
  printf("検索結果  ：");
  if(rc!=-1){
    printf("キーワードは%d文字目に検索されました\n",rc+1);
  }else{
    printf("キーワードは検索されませんでした\n");
  }
  return 0;
}