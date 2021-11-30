#include <stdio.h>
#include <string.h>
#define N 8  //データ件数

typedef struct person{
    int id; //会員番号
    char name[20]; //名前
}Person;


// 会員番号による検索関数(線形探索)
int LinearSearch_id(Person x[],int n, int y){
    int i=0;
    while(i<n){
        //目標データとの比較は構造体メンバのid
        if(x[i].id == y) return i;
        else i++;
    }
    return -1;
}


//名前による関数検索(線形探索)
int LinearSearch_name(Person x[], int n, char y[]){
    int i=0;
    while(i<n){
        // 文字列同士が一致しているか
        if(strcmp(x[i].name,y) == 0) return i;
        else i++;
    }
    return -1;
}

void main(){
    Person data[N]={{101,"Ann"},{202,"aaa"},
                    {303,"kkk"},{404,"bbb"},
                    {505,"hhh"},{606,"sss"},
                    {707,"ggg"},{808,"fff"}};
    int target_id;
    char target_name[20];
    int rc;

    //会員番号で検索
    printf("\n会員番号を入力:");
    scanf("%d",&target_id);
    rc = LinearSearch_id(data, N, target_id);
    if(rc==-1) printf("見つかりません\n");
    else printf("要素番号:%d 会員番号:%d 名前:%s\n",rc,data[rc].id,data[rc].name);

    //名前で検索
    printf("\n名前を入力:");
    scanf("%s",target_name);
    rc = LinearSearch_name(data, N, target_name);
    if(rc==-1) printf("見つかりません\n");
    else printf("要素番号:%d 会員番号:%d 名前:%s\n",rc,data[rc].id,data[rc].name);
    return;
}
