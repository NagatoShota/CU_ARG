#include <stdio.h>
#include <stdlib.h>


// 各ノードのための構造体を Node型 と定義。
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;


//キューの準備
#define MAX_NUM 10
Node* queue[MAX_NUM];
int first=0;
int last=0;
void enqueue(Node*);
Node* dequeue(void);


//関数のプロトタイプ宣言
Node* new_node(int);
Node* insert_tree(int, Node*);
Node* search_tree(int, Node*);
void traverse_pre_order(Node*);
void traverse_in_order(Node*);
void traverse_post_order(Node*);
void traverse_level_order(Node*);
void free_tree(Node*);


int main(void)
{
   int x;
   Node* p;
   Node* root=NULL;
 
   printf("\n=データの入力=\n");
   while(1){
      printf("データを入力してください (-1で終了)：");
      scanf("%d",&x);
      if(x==-1)break;
      else root=insert_tree(x,root);
   }
 
   printf("\n\n=全データ表示=");
   printf("\n行きがけ順\n");
   traverse_pre_order(root);
   printf("\n通りがけ順\n");
   traverse_in_order(root);
   printf("\n帰りがけ順\n");
   traverse_post_order(root);
   printf("\nレベル順\n");
   traverse_level_order(root);
    
   printf("\n\n=データの検索=\n");
   while(1){
      printf("検索目標（-1で終了）：");
      scanf("%d",&x);
      if(x==-1)break;
      p=search_tree(x,root);
      if(p!=NULL) printf("見つかりました\n");
      else printf("見つかりませんでした\n");
   }
 
   free_tree(root);
}


// 追加するデータ x を引数として入力。
Node* new_node(int x){
    // 新しいノードのための領域を確保しデータを格納。
    Node* p;
    p=(Node*)malloc(sizeof(Node));
    p->data  = x;
    p->left  = NULL;
    p->right = NULL;
    // データの入った新しいノードへのポインタを戻り値として返し終了。
    return p;
}


// // === 繰り返しによる2分探索木へのデータ追加 ===
// //2分探索木の根へのポインタ
// Node* insert_tree(int x, Node* root){
//     Node* p;

//     // 入力されたrootがNULLでツリーが空の場合は新たに根ノードとなる新ノードへのポインタを返し終了
//     if(root == NULL) return new_node;

//     // 新しいノードxと比較するノードの位置pを根として初期化
//     p=root; 
//     while(1){
//         // 追加するデータxの方が小さければ
//         if(x < p->data){
//             // 左の子があれば比較位置を左の子に移動
//             if(p->left != NULL) p = p->left;
//             else {
//                 // 左の子がなければ作成した新ノードを左の子として追加
//                 p->left = new_node(x);
//                 // 根へのポインタを返して終了
//                 return root;
//             }
//         // 追加するデータxの方が大きければ
//         }else {
//             // 右の子があれば比較位置を右の子に移動
//             if(p->right != NULL) p = p->right;
//             else{
//                 // 右の子がなければ作成したデータを右の子として追加
//                 p->right = new_node;
//                 // 根へのポインタを返して終了
//                 return root;
//             }
//         }
//     }

// }


// === 再起呼び出しによる2分探索木へのデータ追加 ===
Node* insert_tree(int x, Node* root){
    // 入力された二分探索木が空であった場合には、追加するデータを格納した新しいノードを根とする。
    if(root == NULL) return new_node(x);
    // 追加するデータの方が小さい場合には、左の子を根とする部分木にデータを追加。
    if(x < root->data) root->left = insert_tree(x,root->left);
    // 追加するデータの方が大きい場合には、右の子を根とする部分木にデータを追加。
    else root->right = insert_tree(x,root->right);
    // 根へのポインタを返して終了
    return root;
}


// // === 繰り返しによる2分探索木の検索 ===
// // 検索目標x,検索目標2分探索木の根へのポインタroot
// Node* search_tree(int x, Node* root){
//     // 比較して調べるノードへのポインタ p を宣言して、根ノード root に初期化。
//     Node* p=root;
//     while(p!=NULL){
//         // みつかればpを返す
//         if(x==p->data) return p;
//         // 検索目標の方が小さい時は左の子のノードへ移動
//         else if(x < p->data) p = p->left;
//         // 検索目標の方が大きい時は右の子のノードへ移動
//         else p = p->right;
//     }
//     // 見つからなければNULLを返す
//     return NULL;
// }


// === 再帰呼び出しによる2分探索木の検索 ===
Node* search_tree(int x, Node* root){
    // 検索対象の二分探索木が空だった場合は、見つからなかったということでNULLを返し終了。
    if(root == NULL) return NULL;
    // 検索目標と一致した場合は、そのノードへのポインタを返し終了。
    if(x == root->data) return root;
    // 検索目標の方が小さかった場合には、左の子ノードを根とする部分木を検索。
    if(x < root->data) return search_tree(x,root->left);
    // 検索目標の方が大きかった場合には、右の子ノードを根とする部分木を検索。
    else return search_tree(x,root->right);
 
}


// === 行きがけ順による巡回 ===
void traverse_pre_order(Node* root){
    // rootが空なら何もせず終了
    if (root == NULL) return;
    // 根のノードのデータを画面表示
    printf("%d\t", root->data);
    // 左のノードを根とする2分木を再帰呼び出しにより巡回
    traverse_pre_order(root->left);
    // 右のノードを根とする2分木を再帰呼び出しにより巡回
    traverse_pre_order(root->right);
}


// === 通りかけ順による巡回 中 ===
void traverse_in_order(Node* root){
    if (root == NULL) return;
    traverse_in_order(root->left);
    printf("%d\t", root->data);
    traverse_in_order(root->right);
}


// === 帰りかけ順による巡回 後 ===
void traverse_post_order(Node* root)
{
   if(root==NULL)return;
   traverse_post_order(root->left);
   traverse_post_order(root->right);
   printf("%d\t",root->data);
}


// === 2分木のメモリ解放 ===
void free_tree(Node* root)
{
   if(root==NULL)return;
   free_tree(root->left);
   free_tree(root->right);
   free(root);
}


// === 幅優先探索による巡回 ===
void traverse_level_order(Node* root){
    int x;
    Node* p;
    // ツリーの根へのポインタをキューに追加。
    enqueue(root);
    while(1){
        // キューから取り出したポインタをpとする。
        p=dequeue();
        // pに該当するポインタがなければ終了
        if(p==NULL) return;
        // pの指すノードに格納されたデータを表示
        printf("%d\t",p->data);
        // p の左の子をキューに追加。
        if(p->left!=NULL) enqueue(p->left);
        // p の右の子をキューに追加。
        if(p->right!=NULL) enqueue(p->right);
    }
}


void enqueue(Node* data)
{
   if( (last+1)%MAX_NUM == first ){
      printf("キューは満杯で、追加できません\n");
      return;
   }
   queue[last]=data;
   last=(last+1)%MAX_NUM;
   return;
}
 
Node* dequeue(void)
{
   Node* ret;
   if(first==last){
      //printf("キューにデータがありません\n");
      return NULL;
   }
   ret=queue[first];
   first=(first+1)%MAX_NUM;
   return ret;
}