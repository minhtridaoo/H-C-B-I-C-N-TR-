#include <bits/stdc++.h>

using namespace std;

class SoPhuc
{
private:
    int thuc, ao;

public:
    SoPhuc(int thuc = 0, int ao = 0)
    {
        this->thuc = thuc;
        this->ao = ao;
    }

    friend istream &operator>>(istream &in, SoPhuc &s)
    {
        cout << "Nhap phan thuc: ";
        in >> s.thuc;
        cout << "Nhap phan ao: ";
        in >> s.ao;
        return in;
    }
    friend ostream &operator<<(ostream &out, SoPhuc s)
    {
        if (s.ao == 0)
        {
            out << "So phuc do la: ";
            out << s.thuc << endl;
        }
        else
        {
            cout << "So phuc do la: ";
            out << s.thuc << " + " << s.ao <<"i"<< endl;
        }
        return out;
    }

    SoPhuc operator+(SoPhuc &other)
    {
        return SoPhuc(thuc + other.thuc, ao + other.ao);
    }
    SoPhuc operator-(SoPhuc &other)
    {
        return SoPhuc(thuc - other.thuc, ao - other.ao);
    }
   
};

int main()
{
    SoPhuc a, b;
    cin >> a >> b;
    SoPhuc c;
    c = a + b;
    cout << c;
}


