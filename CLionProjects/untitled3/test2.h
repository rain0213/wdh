//
// Created by rain on 2020/11/4.
//

#ifndef UNTITLED3_TEST2_H
#define UNTITLED3_TEST2_H

#endif //UNTITLED3_TEST2_H
#include <string>
#include <iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
//2.1
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*Linklist;
void MergeLink(Linklist &LA,Linklist &LB,Linklist &LC){
    Linklist la,lb,lc;
    la=LA->next;
    lb=LB->next;
    LC=lc=LA;
    while (la&&lb){
        if (la->data<=lb->data){
            lc->next=la;
            lc=la;
            la=la->next;
        }
        else{
            lc->next=lb;
            lc=lb;
            lb=lb->next;
        }
        lc->next=la?la:lb;
        delete LB;
    }
}
