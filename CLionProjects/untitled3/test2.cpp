#include<iostream>
#include<malloc.h>
using namespace std;
typedef struct Node
{
    int data;
    struct Node*next;
}LinkNode,*Linklist;
/*
    初始化链表
*/
Linklist Initlist()
{
    Linklist L;
    L=(Linklist)malloc(sizeof(LinkNode));
    L->next=NULL;
    return L;
}
/*
    尾插法建立链表
*/
void CreatFromTail(Linklist L)
{
    int data=-1;
    Linklist s,tail;
    tail=L;
    cin>>data;
    while(data!=-1)
    {
        s=(Linklist)malloc(sizeof(LinkNode));
        s->data=data;
        tail->next=s;
        tail=s;
        cin>>data;
    }
    tail->next=NULL;
}
/*
    输出链表
*/
void PrintList(Linklist L)
{
    Linklist p=L->next;
    while(p)
    {
        cout<<p->data;
        p=p->next;
    }
}
/*
    合并链表
*/
void merge(Linklist LA,Linklist LB)
{
    Linklist p=LA->next;
    while(p->next)
    {
        p=p->next;
    }
    p->next=LB->next;
    free(LB);
    //PrintList(LA);
}
int main()
{
    Linklist LA,LB;
    LA=Initlist();
    LB=Initlist();
    CreatFromTail(LA);
    PrintList(LA);
    CreatFromTail(LB);
    PrintList(LB);
    cout<<endl;
    merge(LA,LB);
    PrintList(LA);
    system("pause");
    return 0;
}