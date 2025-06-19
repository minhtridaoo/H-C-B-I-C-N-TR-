#include <iostream>
#include <bits/stdc++.h>


using namespace std;

class CTimeSpan {
private:
    int h, m, s;
    bool isNegative = false;
    bool flag = false;

public:
    // Các hàm getter/setter
    void setH(int hour) { h = hour; }
    void setM(int minute) { m = minute; }
    void setS(int second) { s = second; }
    void setNegative(bool neg) { isNegative = neg; }
    int getH() { return h; }
    int getM() { return m; }
    int getS() { return s; }
    bool getflag() { return flag; }

    // Chuyển đổi sang giây
    int to_seconds() {
        return h * 3600 + m * 60 + s;
    }

    // Toán tử nhập
    friend istream& operator>>(istream &is, CTimeSpan &ct) {
        cout << "NHAP KHOANG THOI GIAN\n";
        ct.flag = true;
        cout << "Nhap gio: "; is >> ct.h;
        cout << "Nhap phut: "; is >> ct.m;
        cout << "Nhap giay: "; is >> ct.s;
        
        // Chuẩn hóa thời gian
        ct.m += ct.s / 60;
        ct.s %= 60;
        ct.h += ct.m / 60;
        ct.m %= 60;
        
        return is;
    }

    // Toán tử xuất
    friend ostream& operator<<(ostream &os, CTimeSpan ct) {
        if (ct.isNegative) {
            os << "Khoang thoi gian: -" << ct.h << " gio " << ct.m << " phut " << ct.s << " giay\n";
        } else {
            os << "Khoang thoi gian: " << ct.h << " gio " << ct.m << " phut " << ct.s << " giay\n";
        }
        return os;
    }

    // Toán tử cộng
    friend CTimeSpan operator+(CTimeSpan a, CTimeSpan b) {
        CTimeSpan result;
        int total = a.to_seconds() + b.to_seconds();
        
        if (total < 0) {
            result.isNegative = true;
            total = -total;
        }
        
        result.h = total / 3600;
        total %= 3600;
        result.m = total / 60;
        result.s = total % 60;
        
        return result;
    }

    // Toán tử trừ
    friend CTimeSpan operator-(CTimeSpan a, CTimeSpan b) {
        CTimeSpan result;
        int diff = a.to_seconds() - b.to_seconds();
        
        if (diff < 0) {
            result.isNegative = true;
            diff = -diff;
        }
        
        result.h = diff / 3600;
        diff %= 3600;
        result.m = diff / 60;
        result.s = diff % 60;
        
        return result;
    }

    // Các toán tử so sánh
    friend bool operator==(CTimeSpan a, CTimeSpan b) {
        return a.to_seconds() == b.to_seconds();
    }
    
    friend bool operator!=(CTimeSpan a, CTimeSpan b) {
        return !(a == b);
    }
    
    friend bool operator<(CTimeSpan a, CTimeSpan b) {
        return a.to_seconds() < b.to_seconds();
    }
    
    friend bool operator<=(CTimeSpan a, CTimeSpan b) {
        return a.to_seconds() <= b.to_seconds();
    }
    
    friend bool operator>(CTimeSpan a, CTimeSpan b) {
        return a.to_seconds() > b.to_seconds();
    }
    
    friend bool operator>=(CTimeSpan a, CTimeSpan b) {
        return a.to_seconds() >= b.to_seconds();
    }
};

class CTime {
private:
    int h, m, s;

public:
    // Chuyển đổi sang giây
    int to_seconds() {
        return h * 3600 + m * 60 + s;
    }

    // Toán tử nhập
    friend istream& operator>>(istream &is, CTime &t) {
        cout << "NHAP THOI DIEM\n";
        cout << "Nhap gio: "; is >> t.h;
        cout << "Nhap phut: "; is >> t.m;
        cout << "Nhap giay: "; is >> t.s;
        
        // Chuẩn hóa thời gian
        t.m += t.s / 60;
        t.s %= 60;
        t.h += t.m / 60;
        t.m %= 60;
        t.h %= 24;
        
        return is;
    }

    // Toán tử xuất
    friend ostream& operator<<(ostream &os, CTime &t) {
        os << "Thoi diem: " << t.h << " gio " << t.m << " phut " << t.s << " giay\n";
        return os;
    }

    // Toán tử cộng với số giây
    friend CTime operator+(CTime a, int seconds) {
        CTime result;
        int total = a.to_seconds() + seconds;
        total %= 86400; // 24h = 86400 giây
        if (total < 0) total += 86400;
        
        result.h = total / 3600;
        total %= 3600;
        result.m = total / 60;
        result.s = total % 60;
        
        return result;
    }

    // Toán tử trừ số giây
    friend CTime operator-(CTime a, int seconds) {
        return a + (-seconds);
    }

    // Toán tử tiền tố ++ (tăng 1 giây)
    CTime& operator++() {
        *this = *this + 1;
        return *this;
    }

    // Toán tử hậu tố ++ (tăng 1 giây)
    CTime operator++(int) {
        CTime temp = *this;
        ++(*this);
        return temp;
    }

    // Toán tử tiền tố -- (giảm 1 giây)
    CTime& operator--() {
        *this = *this - 1;
        return *this;
    }

    // Toán tử hậu tố -- (giảm 1 giây)
    CTime operator--(int) {
        CTime temp = *this;
        --(*this);
        return temp;
    }

    // Toán tử trừ hai thời điểm
    friend CTimeSpan operator-(CTime a, CTime b) {
        CTimeSpan result;
        int diff = a.to_seconds() - b.to_seconds();
        
        if (diff < 0) {
            result.setNegative(true);
            diff = -diff;
        }
        
        result.setH(diff / 3600);
        diff %= 3600;
        result.setM(diff / 60);
        result.setS(diff % 60);
        
        return result;
    }

    // Toán tử cộng với khoảng thời gian
    friend CTime operator+(CTime a, CTimeSpan b) {
        int seconds = b.to_seconds();
        return a + seconds;
    }
};

int main()
{
    int step;
    while (step)
    {
        int k;
        cout << "1.Chon 1 de thao tac voi CTimeSpan.\n";
        cout << "2.Chon 2 de thao tac voi CTime.\n";
        cout << "3.Chon 0 de dung chuong trinh.\n\n";
        cout << "Nhap thao tac muon thuc hien: ";
        cin >> k;
        while (k >= 3 || k < 0)
        {
            cout << "Thao tac khong hop le. Vui long chon lai thao tac: ";
            cin >> k;
        }
        if (k == 0)
        {
            cout << "Chuong trinh da dung.";
            return 0;
        }
        if (k == 1)
        {
            CTimeSpan c;
            while (1)
            {
                cout << "\n----------------------------------MENU----------------------------------\n";
                cout << "1. Chon 1 de nhap khoang thoi gian.\n";
                cout << "2. Chon 2 de in ra khoang thoi gian.\n";
                cout << "3. Chon 3 de cong them khoang thoi gian.\n";
                cout << "4. chon 4 de tru di mot khoang thoi gian.\n";
                cout << "5. Chon 0 de dung thao tac. \n";
                cout << "----------------------------------MENU----------------------------------\n\n";
                cout << "Thao tac muon thuc hien: ";
                int step;
                cin >> step;
                while (step > 4 || step < 0)
                {
                    cout << "Thao tac khong hop le. Vui long nhap lai.\n";
                    cout << "Thao tac muon thuc hien: ";
                    cin >> step;
                }
                if (step == 0)
                {
                    cout << "Dung thao tac voi CTimeSpan.\n\n";
                    break;
                }
                if (step == 1)
                {
                    cin >> c;
                }
                else if (step == 2)
                {
                    if (c.getflag() == false)
                    {
                        cout << "Ban chua nhap khoang thoi gian nao.\n";
                    }
                    else
                    {
                        cout << c;
                    }
                }
                else if (step == 3)
                {
                    if (c.getflag() == false)
                    {
                        cout << "Ban chua nhap khoang thoi gian nao.\n";
                    }
                    else
                    {
                        cout << "Nhap khoang thoi gian muon cong:\n\n";
                        CTimeSpan a;
                        cin >> a;
                        cout << "\n";
                        c = a + c;
                        cout << "\n"
                             << "Da cong thanh cong.\n";
                    }
                }
                else if (step == 4)
                {
                    if (c.getflag() == false)
                    {
                        cout << "Ban chua nhap khoang thoi gian nao.\n";
                    }
                    else
                    {
                        cout << "Nhap khoang thoi gian muon tru:\n\n";
                        CTimeSpan a, b;
                        cin >> a;
                        c = c - a;
                        cout << "\n"
                             << "Da tru thanh cong.\n";
                    }
                }
            }
        }
        if (k == 2)
        {
            CTime x;
            cin >> x;
            while (1)
            {
                cout << "\n----------------------------------MENU----------------------------------\n";
                cout << "1. Chon 1 de nhap lai thoi diem.\n";
                cout << "2. Chon 2 de in ra thoi diem vua.\n";
                cout << "3. Chon 3 de cong them mot so nguyen giay.\n";
                cout << "4. chon 4 de tru di mot so nguyen giay.\n";
                cout << "5. Chon 5 de cong thoi diem voi mot khoang thoi gian. \n";
                cout << "6. Chon 6 de tru hai thoi diem de ra mot khoang thoi gian.\n";
                cout << "7. Chon 7 de cong khoang thoi gian len mot giay.\n";
                cout << "8. Chon 8 de tru khoang thoi gian di mot giay.\n";
                cout << "9. Chon 0 de dung thao tac. \n";
                cout << "----------------------------------MENU----------------------------------\n\n";
                cout << "Thao tac muon thuc hien: ";
                int step;
                cin >> step;
                while (step > 8 || step < 0)
                {
                    cout << "Thao tac khong hop le. Vui long nhap lai.\n";
                    cout << "Thao tac muon thuc hien: ";
                    cin >> step;
                }
                if (step == 0)
                {
                    cout << "Dung thao tac voi CTime.\n\n";
                    break;
                }
                else if (step == 1)
                {
                    cin >> x;
                }
                else if (step == 2)
                {
                    cout << x;
                }
                else if (step == 3)
                {
                    int y;
                    cout << "Nhap so nguyen muon cong: ";
                    cin >> y;
                    x = x + y;
                    cout << "\nDa cong thanh cong.\n";
                }
                else if (step == 4)
                {
                    int y;
                    cout << "Nhap so nguyen muon tru: ";
                    cin >> y;
                    x = x - y;
                    cout << "\nDa tru thanh cong.\n";
                }
                else if (step == 5)
                {
                    CTimeSpan z;
                    cin >> z;
                    x = x + z;
                    cout << "\nDa cong thanh cong.\n";
                }
                else if (step == 6)
                {
                    cout << "Nhap hai thoi diem: \n";
                    CTime a, b;
                    cin >> a;
                    cout << "\n";
                    cin >> b;
                    CTimeSpan h = a - b;
                    cout << "\n"
                         << h;
                }
                else if (step == 7)
                {
                    ++x;
                    cout << "Da cong thanh cong.\n";
                }
                else if (step == 8)
                {
                    --x;
                    cout << "Da tru thanh cong.\n";
                }
            }
        }
    }
    return 0;
}