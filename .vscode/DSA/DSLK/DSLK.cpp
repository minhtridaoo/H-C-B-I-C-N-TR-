/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using namespace std;
// ###INSERT CODE HERE -
struct NODE
{
    int info;
    NODE *pNext;
};
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}
NODE *CreateNode(int x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}
void InsertTail(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail ->pNext = p;
        l.pTail = p;
    }
}
void InsertHead(LIST l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void DeleteHead(LIST &l)
{
    if (l.pHead == NULL)
    {
        return;
    }
    NODE *t = l.pHead;
    l.pHead = l.pHead->pNext;
    delete t;
}
void DeleteTail(LIST &l)
{
    if (l.pHead == NULL)
    {
        return;
    }
    if (l.pHead == l.pTail)
    {
        delete l.pHead;
        l.pHead = NULL;
        l.pTail = NULL;
        return;
    }
    NODE *p = l.pHead;
    while (p->pNext != l.pTail)
    {
        p = p->pNext;
    }
    delete l.pTail;
    l.pTail = p;
    l.pTail->pNext = NULL;
}

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

int main()
{
    LIST L;
    CreateEmptyList(L);
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    PrintList(L);
    return 0;
}
