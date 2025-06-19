#include <bits/stdc++.h>

using namespace std;
class SinhVien
{
protected:
    string MSSV;
    string HoTen;
    int TongTinChi;
    string DiaChi;

public:
    SinhVien(string MSSV = "", string HoTen = "", int TongTinChi = 0) : MSSV(MSSV), HoTen(HoTen), TongTinChi(TongTinChi) {}
    virtual void Nhap()
    {

        cout << "Ma so sinh vien: ";
        cin >> MSSV;

        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, HoTen);

        cout << "Tong tin chi: ";
        cin >> TongTinChi;
        cout << "Dia chi: ";
        cin.ignore();
        getline(cin, DiaChi);
    }
    virtual void Xuat()
    {
        cout << "Ma so sinh vien: " << MSSV << endl;
        cout << "Ho ten: " << HoTen << endl;
        cout << "Tong tin chi: " << TongTinChi << endl;
        cout << "Dia chi: " << DiaChi << endl;
    }
    virtual int PhanLoai() = 0;
    virtual double DTB() = 0;
    virtual bool XetTotNghiep() = 0;
};
class DaiHoc : public SinhVien
{
private:
    double DiemLuanVan;
    string TenLuanVan;
    double DiemTrungBinh;

public:
    void Nhap()
    {
        cout << "Vui long nhap thong tin sinh vien dai hoc: " << endl;
        SinhVien::Nhap();

        cout << "Diem luan van: ";
        cin >> DiemLuanVan;
        cin.ignore();
        cout << "Ten luan van: ";
        getline(cin, TenLuanVan);
        cout << "Diem trung binh: ";
        cin >> DiemTrungBinh;
    }
    void Xuat()
    {
        SinhVien::Xuat();

        cout << "Diem trung binh: " << DiemTrungBinh << endl;
        cout << "Diem luan van: " << DiemLuanVan << endl;
        cout << "Ten luan van: " << TenLuanVan << endl;
    }

    int PhanLoai()
    {
        return 1;
    }
    bool XetTotNghiep()
    {
        if (TongTinChi >= 170 && DiemTrungBinh >= 5 && DiemLuanVan >= 5)
        {
            return true;
        }
        return false;
    }
    double DTB()
    {
        return DiemTrungBinh;
    }
};
class CaoDang : public SinhVien
{
private:
    double DiemTotNghiep;
    double DiemTrungBinh;

public:
    void Nhap()
    {
        cout << "Vui long nhap thong tin sinh vien cao dang: " << endl;
        SinhVien::Nhap();
        cout << "Diem tot nghiep: ";
        cin >> DiemTotNghiep;
        cout << "Diem trung binh: ";
        cin >> DiemTrungBinh;
    }
    void Xuat()
    {
        SinhVien::Xuat();
        cout << "Diem tot nghiep: " << DiemTotNghiep << endl;
        cout << "Diem trung binh: " << DiemTrungBinh << endl;
    }

    int PhanLoai()
    {
        return 2;
    }
    bool XetTotNghiep()
    {
        if (TongTinChi >= 120 && DiemTotNghiep >= 5 && DiemTrungBinh >= 5)
        {
            return true;
        }
        return false;
    }
    double DTB()
    {
        return DiemTrungBinh;
    }
};

int main()
{
    SinhVien **sv = new SinhVien *[1000];
    int n;
    int countdaihoc = 0;
    int countcaodang = 0;
    int tong = 0;
    int c;
    do
    {
        cout << "---------------------------MENU------------------------------" << endl;
        cout << "1.Nhap vao danh sach cac sinh vien" << endl;
        cout << "2.Xuat danh sach cac sinh vien" << endl;
        cout << "3.Xuat danh sach cac sinh vien du dieu kien tot nghiep" << endl;
        cout << "4.Xuat danh sach sinh vien khong du dieu kien tot nghiep" << endl;
        cout << "5.Cho biet sinh vien dai hoc nao co diem trung binh cao nhat " << endl;
        cout << "6.Cho biet sinh vien cao dang nao co diem trung binh cao nhat" << endl;
        cout << "7.Voi moi loai, cho biet co bao nhieu sinh vien khong du dieu kien tot nghiep" << endl;
        cout << "0.Thoat" << endl;
        cin >> c;
        if (c == 1)
        {
            cout << "Vui long nhap so luong sinh vien muon nhap: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Chon loai sinh vien:" << endl;
                cout << "1.Sinh vien dai hoc" << endl;
                cout << "2.Sinh vien cao dang" << endl;
                int k;
                cin >> k;
                if (k == 1)
                {
                    sv[tong] = new DaiHoc();
                    sv[tong]->Nhap();
                }
                else if (k == 2)
                {
                    sv[tong] = new CaoDang();
                    sv[tong]->Nhap();
                }
                tong++;
            }
        }
        else if (c == 2)
        {
            cout << "Ban muon xuat danh sach sinh vien nao?" << endl;
            cout << "1.Sinh vien dai hoc" << endl;
            cout << "2.Sinh vien cao dang" << endl;
            cout << "3.Ca hai" << endl;
            int k;
            cin >> k;
            if (k == 1)
            {
                for (int i = 0; i < tong; i++)
                {
                    if (sv[i]->PhanLoai() == 1)
                    {
                        sv[i]->Xuat();
                    }
                }
            }
            else if (k == 2)
            {
                for (int i = 0; i < tong; i++)
                {
                    if (sv[i]->PhanLoai() == 2)
                    {
                        sv[i]->Xuat();
                    }
                }
            }
            else if (k == 3)
            {
                for (int i = 0; i < tong; i++)
                {
                    sv[i]->Xuat();
                }
            }
        }
        else if (c == 3)
        {
            for (int i = 0; i < tong; i++)
            {
                if (sv[i]->XetTotNghiep())
                {
                    sv[i]->Xuat();
                }
            }
        }
        else if (c == 4)
        {
            for (int i = 0; i < tong; i++)
            {
                if (!sv[i]->XetTotNghiep())
                {
                    sv[i]->Xuat();
                }
            }
        }
        else if (c == 5)
        {
            int max1 = INT_MIN;
            for (int i = 0; i < tong; i++)
            {
                if (sv[i]->PhanLoai() == 1 && sv[i]->DTB() > max1)
                {
                    max1 = sv[i]->DTB();
                }
            }
            bool found = false;
            for (int i = 0; i < tong; i++)
            {
                if (sv[i]->PhanLoai() == 1 && sv[i]->DTB() == max1)
                {
                    sv[i]->Xuat();
                }
            }
        }
        else if (c == 6)
        {
            int max1 = INT_MIN;
            for (int i = 0; i < tong; i++)
            {
                if (sv[i]->PhanLoai() == 2 && sv[i]->DTB())
                {
                    max1 = sv[i]->DTB();
                }
            }

            for (int i = 0; i < tong; i++)
            {
                if (sv[i]->PhanLoai() == 2 && sv[i]->DTB() == max1)
                {
                    sv[i]->Xuat();
                }
            }
        }
        else if (c == 7)
        {
            int countk_daihoc = 0;
            int countk_caodang = 0;
            for (int i = 0; i < tong; i++)
            {
                if (sv[i]->PhanLoai() == 1 && !sv[i]->XetTotNghiep())
                {
                    countk_daihoc++;
                }
                if (sv[i]->PhanLoai() == 2 && !sv[i]->XetTotNghiep())
                {
                    countk_caodang++;
                }
            }
            if (countk_caodang != 0 && countk_daihoc != 0)
            {
                cout << "So sinh vien dai hoc khong du dieu kien tot nghiep la: " << countk_daihoc << endl;
                cout << "So sinh vien cao dang khong du dieu kien tot nghiep la: " << countk_caodang << endl;
            }
            else
            {
                cout << "Khong co sinh vien nao thoa man dieu kien" << endl;
            }
        }

    } while (c != 0);
}