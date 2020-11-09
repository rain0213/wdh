//
// Created by rain on 2020/10/27.
//


#include<iostream>
#include <string>
#include <vector>

#include <cstdlib>
#include<fstream>
#include<iomanip>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
using namespace std;
//ADT——顺序表：
typedef struct {
    string id;
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
using namespace std;
int main() {
    SqList L;
    int i = 0, temp, a, c, choose;
    double price;
    Book e;
    string head_1, head_2, head_3;
    cout << "1. 建立\n";
    cout << "2. 输入\n";
    cout << "3. 取值\n";
    cout << "4. 查找\n";
    cout << "5. 插入\n";
    cout << "6. 删除\n";
    cout << "7. 输出\n";
    cout << "0. 退出\n\n";

    choose = -1;
    while (choose != 0) {
        cout << "请选择:";
        cin >> choose;
        switch (choose) {
            case 1://创建顺序表
                if (InitList(L))
                    cout << "成功建立顺序表\n\n";
                else
                    cout << "顺序表建立失败\n\n";
                break;
            case 2: {//顺序表信息输入
                i = 0;
                L.elem = new Book[MAXSIZE];
                if (!L.elem)
                    exit(OVERFLOW);
                L.length = 0;
                fstream file;
                file.open("C:\\Users\\73766\\CLionProjects\\untitled3\\book.txt");
                if (!file) {
                    cout << "错误！未找到文件！" << endl;
                    exit(ERROR);
                }
                file >> head_1 >> head_2 >> head_3;
                while (!file.eof()) {
                    file >> L.elem[i].id >> L.elem[i].name >> L.elem[i].price;
                    i++;
                }
                cout << "输入 book.txt 信息完毕\n\n";
                L.length = i;
                file.close();
            }
                break;
            case 3://顺序表的取值
                cout << "请输入一个位置用来取值：\n";
                cin >> i;
                temp = GetElem(L, i, e);
                if (temp != 0) {
                    cout << "查找成功\n";
                    cout << "第" << i << "本图书的信息是：\n";
                    cout << left << setw(15) << e.id << "\t" << left << setw(50)
                         << e.name << "\t" << left << setw(5) << e.price << endl
                         << endl;
                } else
                    cout << "查找失败！位置超出范围\n\n";
                break;
            case 4: //顺序表的查找
                cout << "请输入所要查找价格:";
                cin >> price;
                temp = LocateElem(L, price);
                if (temp != 0) {
                    cout << "查找成功\n";
                    cout << "该价格对应的书名为：" << L.elem[temp - 1].name << endl << endl;
                } else
                    cout << "查找失败！没有这个价格对应的书籍\n\n";
                break;
            case 5: //顺序表的插入
                cout << "请输入插入的位置和书本信息，包括：编号 书名 价格（用空格隔开）:";
                cin >> a;
                cin >> e.id >> e.name >> e.price; //输入a和b，a代表插入的位置，b代表插入的数值（书本信息）
                if (ListInsert(L, a, e))
                    cout << "插入成功.\n\n";
                else
                    cout << "插入失败.\n\n";
                break;
            case 6: //顺序表的删除
                cout << "请输入所要删除的书籍的位置:";
                cin >> c;
                if (ListDelete(L, c))
                    cout << "删除成功.\n\n";
                else
                    cout << "删除失败.\n\n";
                break;
            case 7: //顺序表的输出
                cout << "当前图书系统信息（顺序表）读出:\n";
                for (i = 0; i < L.length; i++)
                    cout << left << setw(15) << L.elem[i].id << "\t" << left
                         << setw(50) << L.elem[i].name << "\t" << left
                         << setw(5) << L.elem[i].price << endl;
                cout << endl;
                break;
        }
    }
    return 0;
}