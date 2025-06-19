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
    TNode *p;
    p = new TNode;
    if (p == NULL)
        exit(1);
    p->key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}

void Insert(Tree &, int);
bool isFather(Tree, int, int);

void run(int q, Tree T)
{
    // ###INSERT CODE HERE -

    while (q--)

    {
        int a, b;
        cin >> a >> b;

        if (isFather(T, a, b))
        {
            cout << a << " la cha cua " << b << endl;
        }
        else if (isFather(T, b, a))
        {
            cout << b << " la cha cua " << a << endl;
        }
        else
        {
            cout << a << " va " << b << " khong co quan he cha con" << endl;
        }
    }
}

void InsertNode(TNode *&t, int data)
{
    if (t == NULL)
    {
        t = CreateTNode(data);
    }
    else if (data < t->key)
    {
        InsertNode(t->pLeft, data);
    }
    else if (data > t->key)
    {
        InsertNode(t->pRight, data);
    }
}
void Insert(Tree &t, int data)
{
    InsertNode(t.root, data);
}
TNode *Search(TNode *&t, int data)
{
    if (t == NULL)
    {
        return NULL;
    }
    else if (t->key == data)
    {
        return t;
    }
    else if (data < t->key)
    {
        return Search(t->pLeft, data);
    }
    else if (data > t->key)
    {
        return Search(t->pRight, data);
    }
}
bool isFatherfake(TNode *&t, int bo, int con)
{
    if (t == NULL)
    {
        return 0;
    }
    TNode *tmp = Search(t, bo);
    if (tmp == NULL)
    {
        return 0;
    }
    if (bo < tmp->key)
    {
        return isFatherfake(tmp->pLeft, bo, con);
    }
    else if (bo > tmp->key)
    {
        return isFatherfake(tmp->pRight, bo, con);
    }

    bool left = (tmp->pLeft && tmp->pLeft->key == con);
    bool right = (tmp->pRight && tmp->pRight->key == con);
    return left || right;
}
bool isFather(Tree t, int bo, int con)
{
    return isFatherfake(t.root, bo, con);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Tree T;
    CreateTree(T);
    int n;
    cin >> n;
    int data;
    while (n != 0)
    {
        cin >> data;
        Insert(T, data);
        n--;
    }
    int q;
    cin >> q;
    run(q, T);

    return 0;
}
