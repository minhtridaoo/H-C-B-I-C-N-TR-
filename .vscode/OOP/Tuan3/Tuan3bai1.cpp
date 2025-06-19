#include <bits/stdc++.h>

using namespace std;

    class Diem
    {
    private:
        float x, y;

    public:
        Diem(float x = 0, float y = 0)
        {
            this->x = x;
            this->y = y;
        }
        void Nhap();
        void Xuat();
        void TinhTien(float a, float b);
        Diem Quay(float goc);
        float DoDaiCanh(Diem other)
        {
            return sqrt(x * other.x + y * other.y);
        }

        void PhongToDiem(float a, float b)
        {
            x *= a;
            x *= b;
        }
        void PhongNhoDiem(float a, float b)
        {
            x /= a;
            y /= b;
        }
    };

    void Diem::Nhap()
    {
        cout << "Nhap hoanh do: ";
        cin >> x;
        cout << "Nhap tung do: ";
        cin >> y;
    }
    void Diem::TinhTien(float a, float b)
    {
        x += a;
        y += b;
    }
    Diem Diem::Quay(float goc)
    {
        return Diem(x * cos(goc) - y * sin(goc), x * sin(goc) + y * cos(goc));
    }

class TamGiac
{
private:
    Diem a, b, c;
    float AB = a.DoDaiCanh(b);
    float BC = b.DoDaiCanh(c);
    float CA = c.DoDaiCanh(a);

public:
    void NhapDS()
    {
        cout << "Nhap cac diem cua tam giac: ";
        a.Nhap();
        b.Nhap();
        c.Nhap();
    }

    bool KiemTra(float a, float b, float c)
    {
        if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            return true;
        }
        return false;
    }
    void NhanDang(float a, float b, float c)
    {
        if (a == b && b == c && c == a)
        {
            cout << "Day la tam giac deu";
        }
        else if ((a * a + b * b == c * c) || (b * b + c * c == a * a) || (a * a + c * c == b * b))
        {
            cout << "Day la tam giac vuong";
        }
        else if (a == b || b == c || c == a)
        {
            cout << "Day la tam giac can";
        }
        else
        {
            cout << "Day la tam giac thuong";
        }
    }

    float TinhChuVi()
    {

        return AB + BC + CA;
    }
    float TinhDienTich()
    {
        float p = TinhChuVi() / 2.0;
        return sqrt(p * (p - AB) * (p - BC) * (p - CA));
    }
    void QuaycuaTamGiac(float goc)
    {
        a.Quay(goc);
        b.Quay(goc);
        c.Quay(goc);
    }
    void Xuat()
    {
        if (KiemTra(AB, BC, CA))
        {
            NhanDang(AB, BC, CA);
        }
        else
        {
            cout << "Day khong phai la tam giac";
            return;
        }
    }
};

int main()
{
    TamGiac tg;
    tg.NhapDS();
}

//Bai dagiac
#include <bits/stdc++.h>

using namespace std;

class Diem
{
private:
    float x, y;

public:
    Diem(float x = 0, float y = 0)
    {
        this->x = x;
        this->y = y;
    }
    void Nhap();
    void Xuat();
    void TinhTien(float a, float b);
    Diem Quay(float goc);
    float DoDaiCanh(Diem other)
    {
        return sqrt(x * other.x + y * other.y);
    }

    void PhongToDiem(float a, float b)
    {
        x *= a;
        x *= b;
    }
    void PhongNhoDiem(float a, float b)
    {
        x /= a;
        y /= b;
    }
};

void Diem::Nhap()
{
    cout << "Nhap hoanh do: ";
    cin >> x;
    cout << "Nhap tung do: ";
    cin >> y;
}
void Diem::TinhTien(float a, float b)
{
    x += a;
    y += b;
}
Diem Diem::Quay(float goc)
{
    return Diem(x * cos(goc) - y * sin(goc), x * sin(goc) + y * cos(goc));
}

class DaGiac
{
private:
    Diem *d;
    int n;

public:
    void NhapDS()
    {
        cin >> n;
        d = new Diem[n];
        for (int i = 0; i < n; i++)
        {
            d[i].Nhap();
        }
    }

    DaGiac(const DaGiac &obj)
    {
        cin >> n;

        n = obj.n;
        d = new Diem[n];
        for (int i = 0; i < n; i++)
        {
            d[i] = obj.d[i];
        }
    }

    ~DaGiac()
    {
        if (d != NULL)
        {
            delete[] d;
        }
    }
};

int main()
{
}