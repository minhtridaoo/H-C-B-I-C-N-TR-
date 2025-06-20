#include <bits/stdc++.h>

using namespace std;
// tom tắt đề bài:
//  hóa đơn: mahoadon, thongtinkhachhang, ngay lap hoa don, danh sach san pham,tong gia
// Sanpham: maso, tieu de ,gia ban
// tranh anh: kichthuocbuctranh, ten hoa si
// cd: ten ca si, ten don vi san suat
//  moi khach hang: ma khach hang, ten khach hang, sdt

class SanPham
{
protected:
    string MaSo;
    string TieuDe;
    long long GiaBan;

public:
    SanPham() {}
    ~SanPham() {}
    virtual void Nhap()
    {
        cout << "Ma so: ";
        cin >> MaSo;
        cout << "Tieu de: ";
        cin.ignore();
        getline(cin, TieuDe);
        cout << "Gia ban: ";
        cin >> GiaBan;
    }
    virtual void Xuat()
    {
        cout << "Ma so: " << MaSo << endl;
        cout << "Tieu de: " << TieuDe << endl;
        cout << "Gia ban: " << GiaBan << endl;
    }
    int getGiaBan()
    {
        return GiaBan;
    }
};

class TranhAnh : public SanPham
{
private:
    double ChieuDai, ChieuRong;
    string TenHoaSi;

public:
    TranhAnh() {}
    ~TranhAnh() {}
    void Nhap()
    {
        SanPham::Nhap();
        cout << "Chieu dai cua buc tranh: ";
        cin >> ChieuDai;
        cout << "Chieu rong cua buc tranh: ";
        cin >> ChieuRong;
        cout << "Ten hoa si: ";
        cin.ignore();
        getline(cin, TenHoaSi);
    }
    void Xuat()
    {
        SanPham::Xuat();
        cout << "Chieu dai cua buc tranh: " << ChieuDai << endl;
        cout << "Chieu rong cua buc tranh: " << ChieuRong << endl;

        cout << "Ten hoa si: " << TenHoaSi << endl;
    }
};

class CD : public SanPham
{
private:
    string TenCaSi;
    string TenDonViSanXuat;

public:
    CD() {}
    ~CD() {}
    void Nhap()
    {
        SanPham::Nhap();
        cout << "Ten ca si: ";
        cin.ignore();
        getline(cin, TenCaSi);
        cout << "Ten don vi san xuat: ";
        cin >> TenDonViSanXuat;
    }

    void Xuat()
    {
        SanPham::Xuat();
        cout << "Ten ca si: " << TenCaSi << endl;
        cout << "Ten don vi san xuat: " << TenDonViSanXuat << endl;
    }
};

// moi khach hang: ma khach hang, ten khach hang, sdt
class KhachHang
{
private:
    string MaKH;
    string ten;
    string sdt;

public:
    KhachHang()
    {
    }
    ~KhachHang() {}
    void Nhap()
    {
        cout << "Ma khach hang: ";
        cin >> MaKH;
        cout << "Ten: ";
        cin.ignore();
        getline(cin, ten);
        cout << "SDT: ";
        cin >> sdt;
    }
    void Xuat()
    {
        cout << "Ma khach hang: " << MaKH << endl;
        cout << "Ten: " << ten << endl;
        cout << "So dien thoai: " << sdt << endl;
    }
};

//  hóa đơn: mahoadon, thongtinkhachhang, ngay lap hoa don, danh sach san pham,tong gia
class HoaDon
{
private:
    string MaHoaDon;
    KhachHang kh;
    string NgayLapHoaDon;
    int n;
    SanPham *sp[100];
    long long tongGia = 0;

public:
    HoaDon() {}
    ~HoaDon() {}
    void Nhap()
    {
        cout << "Ma hoa don: ";
        cin >> MaHoaDon;

        kh.Nhap();
        cout << "Ngay lap hoa don: ";
        cin >> NgayLapHoaDon;
        cout << "Nhap so luong san pham: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << "1.Chon CD 2.Chon Tranh Anh" << endl;
            int k;
            cin >> k;
            cout << "San pham thu " << i + 1 << ": " << endl;
            if (k == 1)
            {
                sp[i] = new CD();
            }
            else
            {
                sp[i] = new TranhAnh();
            }
            sp[i]->Nhap();
        }
        for (int i = 0; i < n; i++)
        {
            tongGia += sp[i]->getGiaBan();
        }
    }
    //  hóa đơn: mahoadon, thongtinkhachhang, ngay lap hoa don, danh sach san pham,tong gia
    void Xuat()
    {
        cout << "Ma hoa don" << MaHoaDon << endl;
        cout << "Thong tin khach hang: ";
        kh.Xuat();
        cout << endl;
        cout << "Ngay lap hoa don: " << NgayLapHoaDon << endl;

        cout << "Danh sach san pham: " << endl;
        for (int i = 0; i < n; i++)
        {
            sp[i]->Xuat();
        }
        cout << "Tong gia: " << tongGia << endl;
    }
    int getGiaHoaDon()
    {
        return tongGia;
    }
};

int main()
{
    HoaDon **hd = new HoaDon *[100];
    int k;
    int tong = 0;
    do
    {
        cout << "-----------------------------MENU------------------------" << endl;
        cout << "1. Nhập và xuất danh sách các hoá đơn bán hàng " << endl;
        cout << "2.Tính tổng thu nhập của cửa hàng" << endl;
        cout << "3.Tìm các khách hàng mua nhiều nhất ở cửa hàng (dựa vào tổng giá trị các hoá đơn khách hàng đã mua)." << endl;
        cout << "0.Thoat" << endl;
        cin >> k;
        if (k == 1)
        {
            cout << "Vui long nhap so luong khach hang: " << endl;
            int c;
            cin >> c;
            for (int i = 0; i < c; i++)
            {
                hd[i] = new HoaDon();
                hd[i]->Nhap();
                tong++;
            }
            cout << "Danh sach khach hang do la: " << endl;
            for (int i = 0; i < c; i++)
            {
                hd[i]->Xuat();
            }
        }
        else if (k == 2)
        {
            long long sum = 0;
            for (int i = 0; i < tong; i++)
            {
                sum += hd[i]->getGiaHoaDon();
            }
            cout << sum << endl;
        }
        else
        {
            int max1 = INT_MIN;
            for (int i = 0; i < tong; i++)
            {
                if (hd[i]->getGiaHoaDon() > max1)
                {
                    max1 = hd[i]->getGiaHoaDon();
                }
            }
            for (int i = 0; i < tong; i++)
            {
                if (hd[i]->getGiaHoaDon() == max1)
                {
                    hd[i]->Xuat();
                }
            }
        }
    } while (k != 0);
    for (int i = 0; i < tong; i++)
        delete hd[i];
    delete[] hd;
}
