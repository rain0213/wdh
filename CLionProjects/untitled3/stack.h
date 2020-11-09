//
// Created by rain on 2020/11/3.
//

#ifndef UNTITLED3_STACK_H
#define UNTITLED3_STACK_H

#endif //UNTITLED3_STACK_H
#define MAXSIZE 100
#include "math.h"
#include<iostream>
#include <string>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef struct {
    int *base;
    int *top;
    int stacksize;
}SqStack;
//顺序栈的初始化:
int InitStack(SqStack &S){
    S.base=new int [MAXSIZE];
    if (!S.base)
        exit(OVERFLOW);
    S.top=S.base;
    S.stacksize=MAXSIZE;
    return OK;

}
//顺序栈的入栈:
int Push(SqStack &S,int e){
    if (S.top-S.base==S.stacksize)
        return ERROR;
    *S.top++=e;
    return OK;
}
//顺序栈的出栈:
int Pop(SqStack &S,int &e){
    if (S.top==S.base)
        return ERROR;
     e=*--S.top;
     return OK;
}
//取顺序栈的栈顶元素:
int GetTop(SqStack S){
    if (S.top!=S.base)
        return *(S.top-1);
}