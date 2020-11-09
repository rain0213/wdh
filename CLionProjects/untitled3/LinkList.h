//
// Created by rain on 2020/11/2.
//

#ifndef UNTITLED3_LINKLIST_H
#define UNTITLED3_LINKLIST_H
#include <string>
#include <iostream>
#include<iomanip>
#include<fstream>

#endif //UNTITLED3_LINKLIST_H
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
string head_1, head_2, head_3;
int length;

//ADT：链表
typedef struct {
    string id;
    string name;
    double price;
}Book;
typedef struct LNode{
    Book data;
    struct LNode *next;
}LNode,*Linklist;
//单链表的初始化：
int Initlist(Linklist &L){
    L=new LNode;
    L->next=NULL;
    return  OK;
}
//单链表的取值：
int GetElem(Linklist L,int i,Book &e){
    Linklist p;
    int j;
    p=L->next;
    j=1;
    while (p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if (!p||j>i)
        return ERROR;
    e=p->data;
    return OK;
}
//单链表的查找：
LNode *LocateElem(Linklist L,double e){
    Linklist p;
    p=L->next;
    while (p&&p->data.price!=e){
        p=p->next;
    }
    return p;

}
//单链表的插入：
int  ListInsert(Linklist &L,int i,Book e){
    Linklist p,s;
    int j;
    p=L;
    j=0;
    while (p&&j<i-1){
        p=p->next;
        ++j;
    }
    if (!p||j>i-1)
        return ERROR;
    s=new LNode;
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;

}
//单链表的删除：
int  ListDelete(Linklist &L,int i){
    Linklist p,q;
    int j;
    p=L;
    j=0;
    while ((p->next)&&(j<i-1)){
        p=p->next;
        ++j;
    }
    q=p->next;
    p->next=p;
    p->next=q->next;
    delete q;
    return OK;

}
////前插法创建单链表：
//void CreateList_H(Linklist &L,int n){
//    L=new LNode;
//    Linklist p;
//    L->next=NULL;
//    for (int i = 0; i <n ; ++i) {
//        p=new LNode;
//        cin>>p->data.id;
//        cin>>p->data.name;
//        cin>>p->data.price;
//        p->next=L->next;
//        L->next=p;
//
//    }
//}
////后插法创建单链表：
//void  CreateList_R(Linklist &L,int n){
//    L=new LNode;
//    L->next=NULL;
//    Linklist r,p;
//    r=L;
//    for (int i = 0; i <n; ++i) {
//        p=new LNode;
//        cin>>p->data.id;
//        cin>>p->data.name;
//        cin>>p->data.price;
//        p->next=NULL;
//        r->next=p;
//        r=p;
//    }
//}
void CreateList_H(Linklist &L, int n) { //算法2.11 前插法创建单链表
    //逆位序输入n个元素的值，建立到头结点的单链表L
    Linklist  p;
    L = new LNode;
    L->next = NULL; //先建立一个带头结点的空链表
    length = 0;
    fstream file;
    file.open("book.txt");
    if (!file) {
        cout << "未找到相关文件，无法打开！" << endl;
        exit(ERROR);
    }
    file >> head_1 >> head_2 >> head_3;
    while (!file.eof()) {
        p = new LNode; //生成新结点*p
        file >> p->data.id >> p->data.name >> p->data.price; //输入元素值赋给新结点*p的数据域
        p->next = L->next;
        L->next = p; //将新结点*p插入到头结点之后
        length++;//同时对链表长度进行统计
    }
    file.close();
} //CreateList_F

void CreateList_R(Linklist  &L, int n) { //算法2.12 后插法创建单链表
    //正位序输入n个元素的值，建立带表头结点的单链表L
    Linklist p, r;
    L = new LNode;
    L->next = NULL; //先建立一个带头结点的空链表
    r = L; //尾指针r指向头结点
    length = 0;
    fstream file; //打开文件进行读写操作
    file.open("book.txt");
    if (!file) {
        cout << "未找到相关文件，无法打开！" << endl;
        exit(ERROR);
    }
    file >> head_1 >> head_2 >> head_3;
    while (!file.eof()) { //将文件中的信息运用后插法插入到链表中
        p = new LNode;//生成新结点
        file >> p->data.id >> p->data.name >> p->data.price;//输入元素值赋给新结点*p的数据域
        p->next = NULL;
        r->next = p;//将新结点*p插入尾结点*r之后
        r = p;//r指向新的尾结点*p
        length++; //同时对链表长度进行统计
    }
    file.close();
} //CreateList_L
//遍历输出链表中各个结点的递归算法
void TraverseList(Linklist p){
    if (p==NULL)
        return;
    else
    {
        cout<<p->data.name<<endl;
        TraverseList(p->next);
    }
}