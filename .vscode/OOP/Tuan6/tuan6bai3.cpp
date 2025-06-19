// DE HK2 2015-2016

#include <bits/stdc++.h>

using namespace std;

class KyHieu
{
protected:
    double TruongDo;

public:
    KyHieu(double TruongDo = 0) : TruongDo(TruongDo) {}
    virtual void Nhap()
    {
        cout << "Vui long nhap truong do: " << endl;
        cout << "1.Not(Dau lang) tron" << endl;
        cout << "2.Not(Dau lang) trang" << endl;
        cout << "3.Not(Dau lang) den" << endl;
        cout << "4.Not(Dau lang) moc don" << endl;
        cout << "5.Not(Dau lang) moc doi" << endl;
        cout << "6.Not(Dau lang) moc tam" << endl;
        cout << "7.Not(Dau lang) moc tu" << endl;
        cin >> TruongDo;
        if (TruongDo == 1)
        {
            TruongDo = 4;
        }
        else if (TruongDo == 2)
        {
            TruongDo = 2;
        }
        else if (TruongDo == 3)
        {
            TruongDo = 1;
        }
        else if (TruongDo == 4)
        {
            TruongDo = (double)1 / 2;
        }
        else if (TruongDo == 5)
        {
            TruongDo = (double)1 / 4;
        }
        else if (TruongDo == 6)
        {
            TruongDo = (double)1 / 8;
        }
        else if (TruongDo == 7)
        {
            TruongDo = (double)1 / 16;
        }
    }
    virtual void Xuat()
    {
        cout << TruongDo << " ";
    }
    virtual bool LayDauLangDen() = 0;
    virtual int LayCaoDoLonNhat() = 0;
};

class NotNhac : public KyHieu
{
private:
    string CaoDo;

public:
    void Nhap()
    {

        cout << "Vui long nhap cao do: " << endl;
        cout << "1.Do(C)" << endl;
        cout << "2.Re(D)" << endl;
        cout << "3.Mi(E)" << endl;
        cout << "4.Fa(F)" << endl;
        cout << "5.Sol(G)" << endl;
        cout << "6.La(A)" << endl;
        cout << "7.Si(B)" << endl;
        cin >> CaoDo;
        KyHieu::Nhap();
    }

    void Xuat()
    {
        if (CaoDo == "1")
        {
            CaoDo = "C";
        }
        else if (CaoDo == "2")
        {
            CaoDo = "D";
        }
        else if (CaoDo == "3")
        {
            CaoDo = "E";
        }
        else if (CaoDo == "4")
        {
            CaoDo = "F";
        }
        else if (CaoDo == "5")
        {
            CaoDo = "G";
        }
        else if (CaoDo == "6")
        {
            CaoDo = "A";
        }
        else if (CaoDo == "7")
        {
            CaoDo = "B";
        }
        cout << CaoDo;
        KyHieu::Xuat();
    }
    bool LayDauLangDen()
    {
        return false;
    }
    int LayCaoDoLonNhat()
    {
        if (CaoDo == "C")
        {
            return 1;
        }
        else if (CaoDo == "D")
        {
            return 2;
        }
        else if (CaoDo == "E")
        {
            return 3;
        }
        else if (CaoDo == "F")
        {
            return 4;
        }
        else if (CaoDo == "G")
        {
            return 5;
        }
        else if (CaoDo == "A")
        {
            return 6;
        }
        else if (CaoDo == "B")
        {
            return 7;
        }
        return -1;
    }
};
class NotLang : public KyHieu
{
public:
    void Nhap()
    {
        KyHieu::Nhap();
    }
    void Xuat()
    {
        KyHieu::Xuat();
    }
    bool LayDauLangDen()
    {
        if (TruongDo == 1)
        {
            return true;
        }
        return false;
    }
    int LayCaoDoLonNhat()
    {
        return 0;
    }
};

int main()
{
    KyHieu **kh = new KyHieu *[1000];
    int n;
    int tong = 0;
    int k;
    do
    {
        cout << "Vui long dien lua chon" << endl;
        cout << "1.Soan mot ban nhac" << endl;
        cout << "2.Tim va dem co bao nhieu dau lang den trong ban nhac" << endl;
        cout << "3.Cho biet not nhac co cao do cao nhat trong ban nhac" << endl;
        cout << "0.Thoat" << endl;

        int k;
        cin >> k;
        if (k == 1)
        {
            cout << "Vui long nhap so luong not nhac: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "1.Nhap not nhac" << endl;
                cout << "2.Nhap dau lang" << endl;
                int t;
                cin >> t;
                if (t == 1)
                {
                    kh[tong] = new NotNhac();
                    kh[tong]->Nhap();
                }
                else if (t == 2)
                {
                    kh[tong] = new NotLang();
                    kh[tong]->Nhap();
                }
                tong++;
            }
            cout << "Ban nhac sau khi nhap la: " << endl;
            for (int i = 0; i < tong; i++)
            {
                kh[i]->Xuat();
            }
            cout << endl;
        }
        else if (k == 2)
        {
            int count = 0;
            vector<int> vt;

            for (int i = 0; i < tong; i++)
            {
                if (kh[i]->LayDauLangDen())
                {
                    count++;
                    vt.push_back(i);
                }
            }
            cout << "So luong dau lang den la: " << count << endl;
            cout << "Vi tri cac dau lang den: " << endl;
            for (int it : vt)
            {
                cout << it << " ";
            }
        }
        else if (k == 3)
        {
            int max1 = 0;
            int vt = 0;
            bool found = false;
            for (int i = 0; i < tong; i++)
            {
                if (kh[i]->LayCaoDoLonNhat() > max1)
                {
                    max1 = kh[i]->LayCaoDoLonNhat();
                    vt = i;
                    found = true;
                }
            }

            if (found)
            {
                cout << "Not nhac co cao do cao nhat trong ban nhac: ";
                kh[vt]->Xuat();
            }
            else
            {
                cout << "Khong thoa man yeu cau de bai" << endl;
            }
        }

    } while (k != 0);
}