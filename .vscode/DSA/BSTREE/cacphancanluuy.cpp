#include <iostream>
using namespace std;

struct TNode
{
    int key;
    TNode *pLeft;
    TNode *pRight;
};

struct Tree
{
    TNode *root;
};

void CreateTree(Tree &T)
{
    T.root = NULL;
}

TNode *CreateTNode(int x)
{
    TNode *p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}
// tao cay va duyet cay
void Insert(Tree &t, int x)
{
    TNode *n = CreateTNode(x);
    if (t.root == NULL)
    {
        t.root = n;
        return;
    }
    TNode *p = t.root;
    TNode *bome = NULL;
    while (p != NULL)
    {
        bome = p;
        if (x < p->key)
        {
            p = p->pLeft;
        }
        else if (x > p->key)
        {
            p = p->pRight;
        }
        else
        {
            return;
        }
    }
    if (x < bome->key)
    {
        bome->pLeft = n;
    }
    else
    {
        bome->pRight = n;
    }
}
void NLR(TNode *p)
{
    if (p == NULL)
    {
        return;
    }
    cout << p->key << " ";
    NLR(p->pLeft);
    NLR(p->pRight);
}
void InMinMax(Tree t)
{

    if (t.root == NULL)
    {
        return;
    }
    TNode *p = t.root;
    while (p->pLeft != NULL)
    {
        p = p->pLeft;
    }
    int min1 = p->key;
    p = t.root;
    while (p->pRight != NULL)
    {
        p = p->pRight;
    }
    int max1 = p->key;
    cout << "Min: " << min1 << endl;
    cout << "Max: " << max1 << endl;
}

int DemNut(TNode *p) // DEM NUT CUA CAY
{

    if (p == NULL)
    {
        return 0;
    }
    return 1 + DemNut(p->pLeft) + DemNut(p->pRight);
}
int GetHeight(TNode *p) // chieu cao cua cay

{
    if (p == NULL)
    {
        return -1;
    }
    int hleft = GetHeight(p->pLeft);
    int hright = GetHeight(p->pRight);
    return 1 + (hleft > hright ? hleft : hright);
}

// TIM KIEM VA XOA
TNode *Search(TNode *&root, int x)
{
    if (root == NULL || root->key == x)
    {
        return root;
    }
    if (x < root->key)
    {
        return Search(root->pLeft, x);
    }
    if (x > root->key)
    {
        return Search(root->pRight, x);
    }
}

void Delete(TNode *&p, int x)
{
    if (p == NULL)
    {
        return;
    }
    if (x < p->key)
    {
        Delete(p->pLeft, x);
    }
    else if (x > p->key)
    {
        Delete(p->pRight, x);
    }
    else
    {
        if (p->pLeft != NULL && p->pRight != NULL)
        {
            TNode *t = p->pRight;
            while (t->pLeft != NULL)
            {
                t = t->pLeft;
            }
            p->key = t->key;
            Delete(p->pRight, t->key);
        }
        else
        {
            TNode *t = p;
            if (p->pLeft != NULL)
            {
                p = p->pLeft;
            }
            else
            {
                p = p->pRight;
            }
            delete t;
        }
    }
}
// Dem nut la

int DemNutLa(TNode *p)
{
    int count = 0;
    if (p == NULL)
    {

        return 0;
    }
    if (p->pLeft == NULL && p->pRight == NULL)
    {
        return 1;
    }
    return DemNutLa(p->pLeft) + DemNutLa(p->pRight);
}
// Dem nut la le/chan 
int DemNutLa(TNode *p)
{
    int count = 0;
    if (p == NULL)
    {

        return 0;
    }
    if (p->pLeft == NULL && p->pRight == NULL)
    {
        return 1;
    }
    return  DemNutLa(p->pLeft) + DemNutLa(p->pRight);
}
// Dem nut  1con

//Dem nut 2con thi p->left!=NULL && p->right!=NULL
int DemNut1Con(TNode *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int dem = 0;
    if (p->pLeft != NULL && p->pRight == NULL || p->pLeft == NULL && p->pRight != NULL)
    {
        dem = 1;
    }
    return dem+DemNut1Con(p->pRight) + DemNut1Con(p->pLeft);
}
