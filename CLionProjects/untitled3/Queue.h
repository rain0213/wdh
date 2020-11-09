//
// Created by rain on 2020/11/3.
//

#ifndef UNTITLED3_QUEUE_H
#define UNTITLED3_QUEUE_H

#endif //UNTITLED3_QUEUE_H
#define MAXSIZE 100
#include "math.h"
#include<iostream>
#include <string>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef struct {
    int *base;
    int front;
    int rear;
}SqQueue;
//循环队列的初始化：
int InitQueue(SqQueue &Q){
    Q.base=new int[MAXSIZE];
    if (!Q.base)
        exit(OVERFLOW);
    Q.front=0;
    Q.rear=0;
    return OK;
}
//求循环队列长度:
int QueueLength(SqQueue Q){
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}
//循环队列的入队:
int EnQueue(SqQueue &Q,int e){
    if ((Q.rear+1)%MAXSIZE==Q.front)
        return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXSIZE;
    return OK;
}
//循环队列的出队:
int DeQueue(SqQueue &Q,int e){
    if (Q.rear==Q.front)
        return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front-1)%MAXSIZE;
    return OK;
}
//取循环队列的头元素:
int GetHead(SqQueue Q){
    if (Q.front!=Q.rear)
        return Q.base[Q.front];
}

typedef struct QNode{
    int data;
    struct QNode *next;
}QNode,*QueuePtr;
typedef struct {
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;
//链队的初始化:
int InitQueue(LinkQueue &Q){
    Q.front=Q.rear=new QNode;
    Q.front->next=NULL;
    return OK;
}
//链队的入队:
int EnQueue(LinkQueue &Q,int e){
    QueuePtr p;
    p=new QNode;
    p->data=e;
    p->next=NULL;Q.rear->next=p;
    Q.rear=p;
    return OK;
}
//取循环队列的头元素：
int GetHead_Q(LinkQueue Q){
    if (Q.front!=Q.rear)
        return Q.front->next->data;
}
