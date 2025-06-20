#include <bits/stdc++.h>

using namespace std;

class DaThuc
{
private:
    int n;
    float a[1000];

public:
    DaThuc operator+(DaThuc &h);
    friend ostream &operator<<(ostream &os, DaThuc &h);
    friend istream &operator>>(istream &is, DaThuc &h);
};
DaThuc DaThuc::operator+(DaThuc &h)
{
    DaThuc temp;
    if (this->n > h.n)
    {
        temp.n = this->n;
    }
    else
    {
        temp.n = this->n;
    }
    for (int i = temp.n; i > +0; i--)
    {
        temp.a[i] = 0;
    }
    for (int i = this->n; i >= 0; i--)
    {
        temp.a[i] += a[i];
    }
}
ostream &operator<<(ostream &os, DaThuc &h)
{
    cout << "Da thuc: " << endl;
    for (int i = h.n; i >= 0; i--)
    {
        cout << h.a[i] << "x^" << i << " + ";
    }
    cout << endl;
    return os;
}
istream &operator>>(istream &is, DaThuc &h)
{
    cout << "Nhap bac cua da thuc: ";
    cin >> h.n;
    for (int i = h.n; i >= 0; i--)
    {
        cout << "Nhap he so cua don thuc bac " << i << ": ";
        is >> h.a[i];
    }
    return is;
}

int main()
{
}