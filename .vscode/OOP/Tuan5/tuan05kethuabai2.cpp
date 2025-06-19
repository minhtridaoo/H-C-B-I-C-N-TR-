#include <bits/stdc++.h>
using namespace std;

class SinhVien
{
protected:
    string MSSV, HoTen, DiaChi;
    int TongTinChi;

public:
    SinhVien(string MSSV = "", string Hoten = "", string DiaChi = "", int TongTinChi = 0) : MSSV(MSSV), HoTen(HoTen), DiaChi(DiaChi), TongTinChi(TongTinChi) {}

    void Nhap()
    {
        cout << "Vui long nhap thong tin: " << endl;
        cout << "MSSV: ";
        cin >> MSSV;
        cout << "Ho ten: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, HoTen);
        cout << "Dia chi: ";
        getline(cin, DiaChi);
        cout << "Tong tin chi: ";
        cin >> TongTinChi;
    }
    void Xuat()
    {
        cout << "MSSV: " << MSSV << endl;
        cout << "Ho ten: " << HoTen << endl;
        cout << "Dia chi" << DiaChi << endl;
        cout << "Tong tin chi: " << TongTinChi << endl;
    }
};

class CaoDang : protected SinhVien
{
private:
    double DiemToan, DiemVan;

public:
    CaoDang(string MSSV = "", string HoTen = "", string DiaChi = "", int TongTinChi = 0, double DiemToan = 0, double DiemVan = 0) : SinhVien(MSSV, HoTen, DiaChi, TongTinChi), DiemToan(DiemToan), DiemVan(DiemVan) {}

    void NhapThongTin()
    {
        Nhap();

        cout << "Diem van: ";
        cin >> DiemVan;
        cout << "Diem Toan: ";
        cin >> DiemToan;
    }
    void XuatThongTin()
    {
        Xuat();
        cout << "Diem van: " << DiemVan << endl;
        cout << "Diem toan: " << DiemToan << endl;
    }
    double DTB()
    {
        return (DiemToan + DiemVan) / 2;
    }
    bool KiemTra()
    {
        if (TongTinChi >= 110 && DiemToan >= 5 && DiemVan >= 5 && DTB() >= 5)
        {
            return true;
        }
        return false;
    }
};

class DaiHoc : protected SinhVien
{
private:
    string TenLuanVan;
    double DiemLuanVan;
    double DTB;

public:
    DaiHoc(string MSSV = "", string HoTen = "", string DiaChi = "", int TongTinChi = 0, string TenLuanVan = "", double DiemLuanVan = 0, double DTB = 0) : SinhVien(MSSV, HoTen, DiaChi, TongTinChi), TenLuanVan(TenLuanVan), DiemLuanVan(DiemLuanVan), DTB(DTB) {}

    void NhapThongTin()
    {
        Nhap();
        cout << "Ten luan van: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, TenLuanVan);
        cout << "Diem luan van: ";
        cin >> DiemLuanVan;
        cout << "Diem trung binh: ";
        cin >> DTB;
    }
    void XuatThongTin()
    {
        Xuat();
        cout << "Ten luan van: " << TenLuanVan << endl;
        cout << "Diem luan van: " << DiemLuanVan << endl;
        cout << "Diem trung binh: " << DTB << endl;
    }
    bool KiemTra()
    {
        if (TongTinChi >= 145 && DTB >= 5 && DiemLuanVan >= 5)
        {
            return true;
        }
        return false;
    }
    double getDTB()
    {
        return DTB;
    }
};

int main()
{
    vector<DaiHoc> dh;
    vector<CaoDang> cd;
    int n;
    do
    {
        cout << "-----------------------------------------MENU-------------------------------------------------" << endl;
        cout << "1.Nhap vao danh sach cac sinh vien dai hoc, sinh vien cao dang" << endl;
        cout << "2.Xuat danh sach cac sinh vien" << endl;
        cout << "3.Xuat danh sach cac sinh vien du dieu kien tot nghiep" << endl;
        cout << "4.Xuat danh sach cac sinh vien khong du dieu kien tot nghiep" << endl;
        cout << "5.Cho biet sinh vien dai hoc nao co diem trung binh cao nhat" << endl;
        cout << "0.Thoat" << endl;
        cout << "Vui long nhap lua chon: ";
        cin >> n;
        if (n == 1)
        {
            cout << "Ban muon nhap bao nhieu sinh vien dai hoc ? " << endl;
            int k;
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                DaiHoc a;
                a.NhapThongTin();
                dh.push_back(a);
            }
            cout << "Ban muon nhap bao nhieu sinh vien cao dang ? " << endl;
            int l;
            cin >> l;
            for (int i = 0; i < l; i++)
            {
                CaoDang a;
                a.NhapThongTin();
                cd.push_back(a);
            }
        }
        else if (n == 2)
        {

            for (auto &it : dh)
            {
                it.XuatThongTin();
            }
            for (auto &it : cd)
            {
                it.XuatThongTin();
            }
        }
        else if (n == 3)
        {

            if (!dh.empty())
            {
                for (auto &it : dh)
                {
                    if (it.KiemTra())
                    {
                        it.XuatThongTin();
                    }
                }
            }
            if (!cd.empty())
            {
                for (auto &it : cd)
                {
                    if (it.KiemTra())
                    {
                        it.XuatThongTin();
                    }
                }
            }
            else
            {
                cout << "Khong co sinh vien nao thoa man." << endl;
            }
        }
        else if (n == 4)
        {
            if (!dh.empty())
            {
                for (auto &it : dh)
                {
                    if (!it.KiemTra())
                    {
                        it.XuatThongTin();
                    }
                }
            }
            if (!cd.empty())
            {
                for (auto &it : cd)
                {
                    if (!it.KiemTra())
                    {
                        it.XuatThongTin();
                    }
                }
            }
            else
            {
                cout << "Khong co sinh vien nao thoa man." << endl;
            }
        }
        else if (n == 5)
        {
            double max1 = INT_MIN;
            DaiHoc b;
            if (!dh.empty())
            {
                for (auto &it : dh)
                {
                    if (it.getDTB() > max1)
                    {
                        max1 = it.getDTB();
                        b = it;
                    }
                }
            }

            else
            {
                cout << "Khong sinh vien nao thoa man dieu kien." << endl;
                continue;
            }
            b.XuatThongTin();
        }
    } while (n != 0);
}