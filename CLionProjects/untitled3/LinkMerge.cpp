//
// Created by rain on 2020/11/3.
//

#include<iostream>
#include<fstream>
using namespace std;
#define MAXSIZE 100
#define ERROR 0

typedef struct LNode{
    int data;
    LNode *next;
}LNode,*Linklist;
//链式有序表的合并:
void MergeList_L(Linklist &LA,Linklist &LB,Linklist &LC){
    Linklist pa,pb,pc;
        pa=LA->next;
        pb=LB->next;
        LC=LA;
        pc=LC->next;
        while (pa&&pb){
            if (pa->data<=pb->data)
            {
             pc->next=pa;
             pc=pa;
             pa=pa->next;
            }
            else
            {
                pc->next=pa;
                pc=pb;
                pb=pb->next;
            }
        }
        pc->next=pa?pa:pb;
    delete LB;
}