#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Bậc B-Tree là 3 (theo định nghĩa t = ceil(m/2) = ceil(5/2) = 3)
const int T = 3;

class BTreeNode {
public:
    int keys[2 * T - 1];
    BTreeNode* children[2 * T];
    int numKeys;
    bool isLeaf;

    BTreeNode(bool leaf);

    void traverse();
    BTreeNode* search(int k);
    void insertNonFull(int k);
    void splitChild(int i, BTreeNode* y);
    void remove(int k);

    int findKey(int k);
    void removeFromLeaf(int idx);
    void removeFromNonLeaf(int idx);
    int getPredecessor(int idx);
    int getSuccessor(int idx);
    void fill(int idx);
    void borrowFromPrev(int idx);
    void borrowFromNext(int idx);
    void merge(int idx);

    friend class BTree;
};

class BTree {
public:
    BTreeNode* root;

    BTree() { root = nullptr; }

    void traverse() {
        if (root != nullptr) root->traverse();
    }

    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    void insert(int k);
    void remove(int k);
};

// Constructor và duyệt
BTreeNode::BTreeNode(bool leaf) {
    isLeaf = leaf;
    numKeys = 0;
    for (int i = 0; i < 2 * T; i++) children[i] = nullptr;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < numKeys; i++) {
        if (!isLeaf) children[i]->traverse();
        cout << keys[i] << " ";
    }
    if (!isLeaf) children[i]->traverse();
}

// Tìm kiếm
BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < numKeys && k > keys[i]) i++;

    if (keys[i] == k) return this;
    if (isLeaf) return nullptr;

    return children[i]->search(k);
}

// Chèn
void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(true);
        root->keys[0] = k;
        root->numKeys = 1;
    } else {
        if (root->numKeys == 2 * T - 1) {
            BTreeNode* s = new BTreeNode(false);
            s->children[0] = root;
            s->splitChild(0, root);

            int i = (s->keys[0] < k) ? 1 : 0;
            s->children[i]->insertNonFull(k);

            root = s;
        } else {
            root->insertNonFull(k);
        }
    }
}

void BTreeNode::insertNonFull(int k) {
    int i = numKeys - 1;
    if (isLeaf) {
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        numKeys++;
    } else {
        while (i >= 0 && keys[i] > k) i--;
        if (children[i + 1]->numKeys == 2 * T - 1) {
            splitChild(i + 1, children[i + 1]);
            if (keys[i + 1] < k) i++;
        }
        children[i + 1]->insertNonFull(k);
    }
}

void BTreeNode::splitChild(int i, BTreeNode* y) {
    BTreeNode* z = new BTreeNode(y->isLeaf);
    z->numKeys = T - 1;

    for (int j = 0; j < T - 1; j++)
        z->keys[j] = y->keys[j + T];

    if (!y->isLeaf) {
        for (int j = 0; j < T; j++)
            z->children[j] = y->children[j + T];
    }

    y->numKeys = T - 1;

    for (int j = numKeys; j >= i + 1; j--)
        children[j + 1] = children[j];

    children[i + 1] = z;

    for (int j = numKeys - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[T - 1];
    numKeys++;
}

// Xóa
void BTree::remove(int k) {
    if (!root) {
        cout << "Cay B-Tree rong\n";
        return;
    }
    root->remove(k);
    if (root->numKeys == 0) {
        BTreeNode* tmp = root;
        root = (root->isLeaf) ? nullptr : root->children[0];
        delete tmp;
    }
}

int BTreeNode::findKey(int k) {
    int idx = upper_bound(keys, keys + numKeys, k) - keys;
    return idx - (keys[idx - 1] == k && idx > 0);
}

void BTreeNode::removeFromLeaf(int idx) {
    for (int i = idx + 1; i < numKeys; ++i)
        keys[i - 1] = keys[i];
    numKeys--;
}

void BTreeNode::removeFromNonLeaf(int idx) {
    int k = keys[idx];

    if (children[idx]->numKeys >= T) {
        int pred = getPredecessor(idx);
        keys[idx] = pred;
        children[idx]->remove(pred);
    } else if (children[idx + 1]->numKeys >= T) {
        int succ = getSuccessor(idx);
        keys[idx] = succ;
        children[idx + 1]->remove(succ);
    } else {
        merge(idx);
        children[idx]->remove(k);
    }
}

int BTreeNode::getPredecessor(int idx) {
    BTreeNode* cur = children[idx];
    while (!cur->isLeaf)
        cur = cur->children[cur->numKeys];
    return cur->keys[cur->numKeys - 1];
}

int BTreeNode::getSuccessor(int idx) {
    BTreeNode* cur = children[idx + 1];
    while (!cur->isLeaf)
        cur = cur->children[0];
    return cur->keys[0];
}

void BTreeNode::fill(int idx) {
    if (idx != 0 && children[idx - 1]->numKeys >= T)
        borrowFromPrev(idx);
    else if (idx != numKeys && children[idx + 1]->numKeys >= T)
        borrowFromNext(idx);
    else {
        if (idx != numKeys)
            merge(idx);
        else
            merge(idx - 1);
    }
}

void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx - 1];

    for (int i = child->numKeys - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    if (!child->isLeaf) {
        for (int i = child->numKeys; i >= 0; --i)
            child->children[i + 1] = child->children[i];
    }

    child->keys[0] = keys[idx - 1];

    if (!child->isLeaf)
        child->children[0] = sibling->children[sibling->numKeys];

    keys[idx - 1] = sibling->keys[sibling->numKeys - 1];

    child->numKeys++;
    sibling->numKeys--;
}

void BTreeNode::borrowFromNext(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];

    child->keys[child->numKeys] = keys[idx];

    if (!child->isLeaf)
        child->children[child->numKeys + 1] = sibling->children[0];

    keys[idx] = sibling->keys[0];

    for (int i = 1; i < sibling->numKeys; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    if (!sibling->isLeaf) {
        for (int i = 1; i <= sibling->numKeys; ++i)
            sibling->children[i - 1] = sibling->children[i];
    }

    child->numKeys++;
    sibling->numKeys--;
}

void BTreeNode::merge(int idx) {
    BTreeNode* child = children[idx];
    BTreeNode* sibling = children[idx + 1];

    child->keys[T - 1] = keys[idx];

    for (int i = 0; i < sibling->numKeys; ++i)
        child->keys[i + T] = sibling->keys[i];

    if (!child->isLeaf) {
        for (int i = 0; i <= sibling->numKeys; ++i)
            child->children[i + T] = sibling->children[i];
    }

    for (int i = idx + 1; i < numKeys; ++i)
        keys[i - 1] = keys[i];

    for (int i = idx + 2; i <= numKeys; ++i)
        children[i - 1] = children[i];

    child->numKeys += sibling->numKeys + 1;
    numKeys--;

    delete sibling;
}

void BTreeNode::remove(int k) {
    int idx = findKey(k);
    bool found = (idx < numKeys && keys[idx] == k);

    if (isLeaf) {
        if (found)
            removeFromLeaf(idx);
        return;
    }

    if (found) {
        removeFromNonLeaf(idx);
    } else {
        bool flag = (idx == numKeys);
        if (children[idx]->numKeys < T)
            fill(idx);

        if (flag && idx > numKeys)
            children[idx - 1]->remove(k);
        else
            children[idx]->remove(k);
    }
}

int main() {
    BTree t;

    vector<int> keys = {3, 7, 9, 23, 45, 1, 5, 14, 25, 24, 13, 11, 8, 19, 4, 31, 35, 56};
    for (int k : keys) {
        t.insert(k);
    }

    cout << "In cay theo thu tu tu be den lon: ";
    t.traverse();
    cout << endl;

    cout << "\nXoa cac khoa: 4, 5, 7, 3, 14\n";
    t.remove(4);
    t.remove(5);
    t.remove(7);
    t.remove(3);
    t.remove(14);

    cout << "Cay sau khi xoa: ";
    t.traverse();
    cout << endl;

    cout << "\nThem cac khoa: 2, 6, 12\n";
    t.insert(2);
    t.insert(6);
    t.insert(12);

    cout << "Cay sau khi them: ";
    t.traverse();
    cout << endl;

    return 0;
}