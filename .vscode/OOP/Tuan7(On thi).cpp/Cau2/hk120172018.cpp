#include <bits/stdc++.h>

using namespace std;

class Date
{
private:
    int ngay, thang, nam;

public:
    Date();
    Date(int nam, int thang);
    Date(int nam, int thang, int ngay);
    int IsNhuan();
    bool operator<(Date &hs);
    Date operator++(int);
    friend istream &operator>>(istream &is, Date &hs);
    friend ostream &operator<<(ostream &os, Date &hs);
};
Date::Date()
{
    nam = 1;
    thang = 1;
    ngay = 1;
}
Date::Date(int nam, int thang)
{
    this->nam = nam;
    this->thang = thang;
    ngay = 1;
}
Date::Date(int nam, int thang, int ngay)
{
    this->nam = nam;
    this->thang = thang;
    this->ngay = ngay;
}
int Date::IsNhuan()
{
    if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0)
    {
        return 1;
    }
    return 0;
}
istream &operator>>(istream &is, Date &hs)
{
    cout << "Nhap ngay: ";
    is >> hs.ngay;
    cout << "Nhap thang: ";
    is >> hs.thang;
    cout << "Nhap nam: ";
    is >> hs.nam;
    return is;
}
ostream &operator<<(ostream &os, Date &hs)
{
    os << hs.ngay << "/";
    os << hs.thang << "/";
    os << hs.nam << endl;
    return os;
}
bool Date::operator<(Date &hs)
{
    if (nam < hs.nam)
    {
        return true;
    }
    if (thang < hs.thang)
    {

        return true;
    }
    if (ngay < hs.thang)
    {
        return true;
    }
    return false;
}
Date Date::operator++(int)
{
    Date h = *this;
    int ngaytrongthang[13] = {0, 31, 28 + IsNhuan(), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    ++ngay;
    if (ngay > ngaytrongthang[thang])
    {
        thang++;
        if (thang > 12)
        {
            nam++;
            thang = 1;
        }
        ngay = 1;
    }
    return h;
}

int main()
{
    Date h1;
    Date h2(2, 3);
    Date h3(3, 5);
    cin >> h1;
    if (h1 < h2)
    {
        cout << "Ngay 1 truoc ngay 2" << endl;
    }
    else
    {
        cout << "Ngay 1 sau ngay 2" << endl;
    }
}