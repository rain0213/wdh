//
// Created by rain on 2020/11/3.
//
#include<iostream>
#include<fstream>
using namespace std;
#define MAXSIZE 100
#define ERROR 0
typedef struct //定义顺序表
{
    int *elem;
    int length;
} SqList;
//顺序有序表的合并:
void MergeList_Sq(SqList &LA,SqList &LB,SqList &LC){
    int *pa, *pb, *pc, *pa_last, *pb_last;
    LC.length=LA.length+LB.length;
    LC.elem=new int [LC.length];
    pc=LC.elem;
    pa=LA.elem;
    pb=LB.elem;
    pa_last=LA.elem+LA.length-1;
    pb_last=LB.elem+LB.length-1;
    while ((pa<=pa_last)&&(pb<=pb_last)){
        if (*pa<=*pb)
            *pc++=*pa++;
        else
            *pc++=*pb++;

    }
    while (pa<=pa_last)
        *pc++=*pa++;
    while (pb<=pb_last)
        *pc++=*pb++;
}