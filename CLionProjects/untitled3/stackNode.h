//
// Created by rain on 2020/11/3.
//

#ifndef UNTITLED3_STACKNODE_H
#define UNTITLED3_STACKNODE_H

#endif //UNTITLED3_STACKNODE_H
#define MAXSIZE 100
#include "math.h"
#include<iostream>
#include <string>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef struct StackNode{
    int data;
    struct StackNode *next;
}StackNode,*LinkStack;
//链栈的初始化:
int InitStack(LinkStack &S){
    S=NULL;
    return OK;
}
//链栈的入栈:
int Push(LinkStack &S,int e){
    LinkStack p;
    p=new StackNode;
    p->data=e;
    p->next=S;
    S=p;
    return OK;

}
//链栈的出栈：
int Pop(LinkStack &S,int &e){
    LinkStack p;
    if (S==NULL)
        return ERROR;
    e=S->data;
    p=S;
    S=S->next;
    delete p;
    return OK;

}
//取链栈的栈顶元素:
int GetTop(LinkStack S){
    if(S!=NULL)
        return S->data;
}
