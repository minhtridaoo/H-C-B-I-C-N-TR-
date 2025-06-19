/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

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
    TNode *p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

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
            p = p->pLeft;
        else if (x > p->key)
            p = p->pRight;
        else
        {
            delete n;
            return; // trùng -> không chèn
        }
    }
    if (x < bome->key)
        bome->pLeft = n;
    else
        bome->pRight = n;
}

TNode *Search(TNode *&root, int x)
{
    if (root == NULL || root->key == x)
        return root;
    if (x < root->key)
        return Search(root->pLeft, x);
    else
        return Search(root->pRight, x);
}

void Delete(TNode *&root, int x)
{
    if (root == NULL)
        return;
    if (x < root->key)
        Delete(root->pLeft, x);
    else if (x > root->key)
        Delete(root->pRight, x);
    else
    {
        if (root->pLeft != NULL && root->pRight != NULL)
        {
            TNode *tmp = root->pRight;
            while (tmp->pLeft != NULL)
                tmp = tmp->pLeft;
            root->key = tmp->key;
            Delete(root->pRight, tmp->key);
        }
        else
        {
            TNode *tmp = root;
            if (root->pLeft != NULL)
                root = root->pLeft;
            else
                root = root->pRight;
            delete tmp;
        }
    }
}

void NLR(TNode *p)
{
    if (p == NULL)
        return;
    cout << p->key << " ";
    NLR(p->pLeft);
    NLR(p->pRight);
}

int main()
{
    Tree T;
    CreateTree(T);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Insert(T, x);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        TNode *found = Search(T.root, x);
        if (found == NULL)
        {
            cout << "Khong tim thay nut " << x << endl;
        }
        else
        {
            Delete(T.root, x);
            cout << "Da xoa nut " << x << endl;
        }
    }

    cout << "NLR: ";
    NLR(T.root);
    cout << endl;

    return 0;
}
