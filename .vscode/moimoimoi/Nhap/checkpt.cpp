#include <iostream>
using namespace std;

struct PhanSo
{
    int tuso;
    int mauso;
};

// Nhập phân số
void nhapmang(PhanSo &a)
{
    cin >> a.tuso >> a.mauso;
}

// In phân số
void outputArray(const PhanSo &a)
{
    cout << a.tuso << "/" << a.mauso;
}

// Tính UCLN (gcd) của 2 số
int gcdd(int a, int b)
{
    while (b != 0)
    {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

// Tính BCNN (lcm) của 2 số
int lcm(int a, int b)
{
    return a / gcdd(a, b) * b;
}

// Rút gọn phân số
void kiemtramauso(PhanSo &a)
{
    int gcd = gcdd(a.tuso, a.mauso);
    a.tuso /= gcd;
    a.mauso /= gcd;
}

// Tính toán hai phân số dựa trên phép toán
PhanSo kiemtra(PhanSo a, PhanSo b, char s)
{
    PhanSo result;
    if (s == '+')
    {
        int mc = lcm(a.mauso, b.mauso);
        result.tuso = (mc / a.mauso) * a.tuso + (mc / b.mauso) * b.tuso;
        result.mauso = mc;
    }
    else if (s == '-')
    {
        int mc = lcm(a.mauso, b.mauso);
        result.tuso = (mc / a.mauso) * a.tuso - (mc / b.mauso) * b.tuso;
        result.mauso = mc;
    }
    else if (s == '*')
    {
        result.tuso = a.tuso * b.tuso;
        result.mauso = a.mauso * b.mauso;
    }
    else if (s == '/')
    {
        result.tuso = a.tuso * b.mauso;
        result.mauso = a.mauso * b.tuso;
    }
    kiemtramauso(result);
    return result;
}

// Hàm main
int main()
{
    PhanSo s1, s2;
    nhapmang(s1);
    nhapmang(s2);
    char s;
    cin >> s;

    // Tính toán kết quả
    PhanSo result = kiemtra(s1, s2, s);

    // Xuất kết quả
    outputArray(result);
    return 0;
}
