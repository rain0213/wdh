//
// Created by rain on 2020/10/27.
//

#ifndef UNTITLED3_LIST_H
#define UNTITLED3_LIST_H
#define MAXSIZE 100
#include "math.h"
#include<iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
//ADT——顺序表：
typedef struct {
    int  id;
    string name;
    double price;
}Book;//顺序表中的数据结构体
typedef struct {
    Book *elem;
    int length;
}SqList;//顺序表中的结构体数据类型


//创建一个空顺序表
int InitList(SqList &L){
    L.elem=new Book [MAXSIZE];
    if (!L.elem)
        exit(OVERFLOW);
    L.length=0;
    return 1;
}
//顺序表的取值
int GetElem(SqList L,int i,Book &e){
    if (i<1||i>L.length)
        return ERROR;

    e=L.elem[i-1];
    return OK;
}
//顺序表的查找
int LocateElem(SqList L,float e){
    for (int i = 0; i <L.length ; i++) {
        if (L.elem[i].price==e) return i+1;
        return 0;
    }
}
//顺序表的插入
int ListInsert(SqList &L,int i,Book e){
    if ((i<1)||(i>L.length+1))
        return ERROR;
    if (L.length==MAXSIZE)
        return ERROR;
    for (int j = L.length-1; j >=i; j--)
        L.elem[j+1]=L.elem[j];
        L.elem[i-1]=e;
        ++L.length;
    return OK;

}
//顺序表的删除
int ListDelete(SqList &L,int i){
    if (i<1||i>L.length)
        return ERROR;
    for (int j = i; j <=L.length ; j++)
        L.elem[j-1]=L.elem[j];
    --L.length;
    return OK;
}
//求线性表长度：
int ListLength(SqList L){
    return L.length;
}
//线性表的合并：
void MergeList(SqList &LA,SqList &LB){
    int m,n;
    Book e;
    m=ListLength(LA),n=ListLength(LB);
    for (int i = 0; i <n ; ++i) {
        GetElem(LB,i,e);
        if (!LocateElem(LA,e.price))
            ListInsert(LA,++m,e);
    }
}





#endif //UNTITLED3_LIST_H
