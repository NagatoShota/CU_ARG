#include <stdio.h>

typedef struct student{
    int grade;
    char name[2][20];
}Student;

Student data[5] = {{2,{"いとう","たけし"}},
                   {2,{"かとう","まさる"}},
                   {2,{"いとう","ありさ"}},
                   {1,{"たなか","はるき"}},
                   {3,{"かとう","さちこ"}},};

// 学年で並び替え(基本選択法)
void SelectionSort_grade(Student x[], int n){
    int max_id;
    Student tmp;

    for (int j=7;j>=1;j--){
        max_id = 0;
        for(int i=1;i<=j;i++){
            if(x[max_id].grade<x[i].grade) max_id = i;
        }
        tmp = x[j];
        x[j] = x[max_id];
        x[max_id] = tmp;
    }
    return;
}

//名前で並び替え(基本選択法)
void SelectionSort_name(Student x[], int n,int f){
    int max_id;
    Student tmp;

    for (int j=7;j>=1;j--){
        max_id = 0;
        for(int i=1;i<=j;i++){
            if(strcmp(x[max_id].name[f],x[i].name[f])) max_id = i;
        }
        tmp = x[j];
        x[j] = x[max_id];
        x[max_id] = tmp;
    }
    return;
}

//学年で並び替え(基本挿入法)
void InsertionSort_grade(Student x[],int n){
    int i,j;
    Student tmp;
    for(j=1;j<n;j++){
        tmp=x[j];
        for(i=j-1;i>=0;i--){
            if(x[i].grade>tmp.grade) x[i+1]=x[i];
            else break;
        }
        x[i+1]=tmp;
    }
    return;
}

//名前で並び替え(基本挿入法)
void InsertionSort_grade(Student x[],int n,int f){
    int i,j;
    Student tmp;
    for(j=1;j<n;j++){
        tmp=x[j];
        for(i=j-1;i>=0;i--){
            if(strcmp(x[i].name[f],tmp.name[f])) x[i+1]=x[i];
            else break;
        }
        x[i+1]=tmp;
    }
    return;
}

