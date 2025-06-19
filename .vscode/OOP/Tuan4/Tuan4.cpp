#include <bits/stdc++.h>

using namespace std;

class CTimeSpan
{
private:
    long long gio, phut, giay;

public:
    CTimeSpan(int gio = 0, int phut = 0, int giay = 0)
    {
        this->gio = gio;
        this->phut = phut;
        this->giay = giay;
    }
    friend istream &operator>>(istream &in, CTimeSpan &time)
    {
        cout << "Gio: ";
        in >> time.gio;
        cout << "Phut: ";
        in >> time.phut;
        cout << "Giay: ";
        in >> time.giay;
        return in;
    }

    friend ostream &operator<<(ostream &out, CTimeSpan &time)
    {
        cout << "Khoang thoi gian do la: " << time.gio << " gio " << time.phut << " phut " << time.giay << " giay";
        return out;
    }

    long long Chuyendoi()
    {

        long long newGio = gio * 3600;
        long long newPhut = phut * 60;
        return (newGio + newPhut + giay);
    }

    CTimeSpan operator+(CTimeSpan &other)
    {
        return CTimeSpan(gio + other.gio, phut + other.phut, giay + other.giay);
    }

    CTimeSpan operator-(CTimeSpan &other)
    {
        return CTimeSpan(gio - other.gio, phut - other.phut, giay - other.giay);
    }
    bool operator==(CTimeSpan &other)
    {
        return Chuyendoi() == Chuyendoi();
    }
    bool operator!=(CTimeSpan &other)
    {
        return Chuyendoi() != Chuyendoi();
    }
    bool operator<=(CTimeSpan &other)
    {
        return Chuyendoi() <= Chuyendoi();
    }
    bool operator<(CTimeSpan &other)
    {
        return Chuyendoi() < Chuyendoi();
    }
    bool operator>=(CTimeSpan &other)
    {
        return Chuyendoi() >= Chuyendoi();
    }
    bool operator>(CTimeSpan &other)
    {
        return Chuyendoi() > Chuyendoi();
    }
    void ChuyenHoa()
    {
        long long ChuyenDoiGiay = Chuyendoi();
        gio = ChuyenDoiGiay / 3600;
        phut = (ChuyenDoiGiay % 3600) / 60;
        giay = ChuyenDoiGiay % 60;
    }
};

class CTime
{
private:
    int gio, phut, giay;

public:
    CTime(int gio = 0, int phut = 0, int giay = 0)
    {
        this->gio = gio;
        this->phut = phut;
        this->giay = giay;
    }
    long long ChuyenDoi()
    {

        return gio * 3600 + phut * 60 + giay;
    }

    friend istream &operator>>(istream &in, CTime &time)
    {
        cout << "Nhap gio: ";
        in >> time.gio;
        cout << "Nhap phut: ";
        in >> time.phut;
        cout << "Nhap giay: ";
        in >> time.giay;
        return in;
    }

    friend ostream &operator<<(ostream &out, CTime &time)
    {
        cout << "Thoi diem do la :";
        cout << time.gio << " gio " << time.phut << " phut " << time.giay << " giay";
        return out;
    }
    void ChuyenHoa()
    {
        long long ChuyenDoiGiay = ChuyenDoi();
        gio = ChuyenDoiGiay / 3600;
        phut = (ChuyenDoiGiay % 3600) / 60;
        giay = ChuyenDoiGiay % 60;
    }

    CTime operator+(int newGiay)
    {
        long long newSecond = ChuyenDoi() + newGiay;

        return CTime(0, 0, newSecond);
    }
    CTime operator-(int newGiay)
    {
        long long newSecond = ChuyenDoi() - newGiay;
        return CTime(0, 0, newSecond);
    }

    CTime &operator++()
    {
        long long newSecond = ChuyenDoi() + 1;
        gio = newSecond / 3600;
        phut = (newSecond % 3600) / 60;
        giay = newSecond % 60;
        return *this;
    }

    CTime operator--()
    {
        long long newSecond = ChuyenDoi() - 1;
        gio = newSecond / 3600;
        phut = (newSecond % 3600) / 60;
        giay = newSecond % 60;
        return *this;
    }

    bool Check()
    {
        if (gio < 0 || phut < 0 || giay < 0)
        {

            return 0;
        }
        return 1;
    }
};
int main()
{
    CTime a;
    cin >> a;
    --a;
    if (a.Check() == 1)
    {
        cout << a;
    }
    else
    {
        cout << "Khong thoa man chuong trinh ";
    }
}
