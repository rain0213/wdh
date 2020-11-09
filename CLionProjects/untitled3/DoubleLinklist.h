//
// Created by rain on 2020/11/2.
//

#ifndef UNTITLED3_DOUBLELINKLIST_H
#define UNTITLED3_DOUBLELINKLIST_H

#endif //UNTITLED3_DOUBLELINKLIST_H
#include <string>
#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
typedef struct {
    string id;
    string name;
    double price;
}Book;
//ADT：双向链表
typedef struct DoubleNode{
    Book data;
    struct DoubleNode *prior;
    struct DoubleNode *next;
}DoubleNode,*Doublelinklist;
//初始化
int InitList_Dul(Doublelinklist &L){
    Doublelinklist p,q;
    L=new DoubleNode;
    L->prior=NULL;
    L->next=NULL;
    return OK;

}
//查找
DoubleNode* GetElem_Dul(Doublelinklist L,int i){
    int j;
    Doublelinklist p;
    p=L->next;
    j=1;
    while (p&&j<i){
        p=p->next;
        ++j;
    }
    if (!p||j>i)
        return NULL;
    return p;
}
//插入
int ListInsert_Dul(Doublelinklist &L,int i,Book e){
    Doublelinklist p,s;
    if (!(p=GetElem_Dul(L,i)))
        return ERROR;
    s=new DoubleNode;
    s->data=e;
    s->prior=p->prior;
    p->prior->next=s;
    p->prior=s;
    s->next=p;
    return OK;
}
//删除
int ListDelete_Dul(Doublelinklist &L,int i){
    Doublelinklist p,s;
    if (!(p=GetElem_Dul(L,i)))
        return ERROR;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    delete p;
    return OK;

}
