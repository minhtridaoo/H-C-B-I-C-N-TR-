#include <bits/stdc++.h>
using namespace std;

class NhanVien
{
protected:
    string HoTen;
    string MSSV;
    int NamSinh;
    int LuongCoBan;

public:
    NhanVien() {}
    virtual ~NhanVien() {}
    virtual void Nhap()
    {
        cin.ignore();
        cout << "Ho ten: ";
        getline(cin, HoTen);
        cout << "MSSV: ";
        cin >> MSSV;
        cout << "Nam sinh: ";
        cin >> NamSinh;
        cout << "Luong co ban: ";
        cin >> LuongCoBan;
    }
    virtual void Xuat()
    {
        cout << "Ho ten: " << HoTen << endl;
        cout << "MSSV: " << MSSV << endl;
        cout << "Nam sinh: " << NamSinh << endl;
        cout << "Luong co ban: " << LuongCoBan << endl;
    }

    virtual long long Luong() = 0;
    virtual int PhanLoai() = 0;
    virtual int getSoPhutVideo() = 0;
    virtual int getSoChienDich() = 0;
};

class BienTapVien : public NhanVien
{
private:
    int SoBaiViet;
    int SoLuotXemBaiViet;

public:
    BienTapVien() {}
    ~BienTapVien() {}
    void Nhap()
    {
        NhanVien::Nhap();
        cout << "So bai viet co ban: ";
        cin >> SoBaiViet;
        cout << "So luot xem bai viet: ";
        cin >> SoLuotXemBaiViet;
    }
    void Xuat()
    {
        NhanVien::Xuat();
        cout << "So bai viet co ban: " << SoBaiViet << endl;
        cout << "So luot xem bai viet: " << SoLuotXemBaiViet << endl;
        cout << "Luong: " << Luong() << endl;
    }
    long long Luong()
    {
        return LuongCoBan + (SoBaiViet * 200000) + (floor)((SoLuotXemBaiViet / 10000) * 500000);
    }
    int PhanLoai()
    {
        return 1;
    }
    int getSoPhutVideo()
    {
        return -1;
    }
    int getSoChienDich()
    {
        return -1;
    }
};

class NguoiDungVideo : public NhanVien
{
private:
    int SoPhutVideo;

public:
    NguoiDungVideo() {}
    ~NguoiDungVideo() {}
    void Nhap()
    {
        NhanVien::Nhap();
        cout << "So phut video hoan thanh: ";
        cin >> SoPhutVideo;
    }
    void Xuat()
    {
        NhanVien::Xuat();
        cout << "So phut video hoan thanh: " << SoPhutVideo << endl;
        cout << "Luong: " << Luong() << endl;
    }
    long long Luong()
    {
        return LuongCoBan + SoPhutVideo * 50000;
    }
    int PhanLoai()
    {
        return 2;
    }
    int getSoPhutVideo()
    {
        return SoPhutVideo;
    }
    int getSoChienDich()
    {
        return -1;
    }
};

class ChuyenVienTruyenThong : public NhanVien
{
private:
    int SoChienDichTruyenThong;

public:
    ChuyenVienTruyenThong() {}
    ~ChuyenVienTruyenThong() {}
    void Nhap()
    {
        NhanVien::Nhap();
        cout << "So chien dich truyen thong: ";
        cin >> SoChienDichTruyenThong;
    }
    void Xuat()
    {
        NhanVien::Xuat();
        cout << "So chien dich truyen thong: " << SoChienDichTruyenThong << endl;
        cout << "Luong: " << Luong() << endl;
    }
    long long Luong()
    {
        return LuongCoBan + SoChienDichTruyenThong * 500000;
    }
    int PhanLoai()
    {
        return 3;
    }
    int getSoChienDich()
    {
        return SoChienDichTruyenThong;
    }
    int getSoPhutVideo()
    {
        return -1;
    }
};

int main()
{
    NhanVien **nv = new NhanVien *[10000];
    int tong = 0, k;

    do
    {
        cout << "\n=========== MENU ===========" << endl;
        cout << "1. Nhap danh sach nhan vien" << endl;
        cout << "2. Tinh tong luong cong ty phai tra" << endl;
        cout << "3. Tim nguoi dung video nhieu phut nhat" << endl;
        cout << "4. Tinh trung binh chien dich cua chuyen vien truyen thong" << endl;
        cout << "0. Thoat" << endl;
        cout << "Chon chuc nang: ";
        cin >> k;

        switch (k)
        {
        case 1:
        {
            int n;
            cout << "Nhap so luong nhan vien: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int loai;
                cout << "\nNhap nhan vien thu " << (tong + 1) << endl;
                cout << "1. Bien tap vien\n2. Nguoi dung video\n3. Chuyen vien truyen thong\nChon: ";
                cin >> loai;

                if (loai == 1)
                    nv[tong] = new BienTapVien();
                else if (loai == 2)
                    nv[tong] = new NguoiDungVideo();
                else if (loai == 3)
                    nv[tong] = new ChuyenVienTruyenThong();
                else
                {
                    cout << "Lua chon khong hop le!" << endl;
                    continue;
                }
                nv[tong]->Nhap();
                tong++;
            }
            break;
        }
        case 2:
        {
            long long sum = 0;
            for (int i = 0; i < tong; i++)
                sum += nv[i]->Luong();
            cout << "Tong luong cong ty can tra: " << sum << endl;
            break;
        }
        case 3:
        {
            int maxPhut = -1, viTri = -1;
            for (int i = 0; i < tong; i++)
            {
                if (nv[i]->PhanLoai() == 2)
                {
                    int soPhut = nv[i]->getSoPhutVideo();
                    if (soPhut > maxPhut)
                    {
                        maxPhut = soPhut;
                        viTri = i;
                    }
                }
            }
            if (viTri != -1)
            {
                cout << "Nguoi dung video co nhieu phut nhat:\n";
                nv[viTri]->Xuat();
            }
            else
                cout << "Khong co nguoi dung video nao!" << endl;
            break;
        }
        case 4:
        {
            int sum = 0, count = 0;
            for (int i = 0; i < tong; i++)
            {
                if (nv[i]->PhanLoai() == 3)
                {
                    sum += nv[i]->getSoChienDich();
                    count++;
                }
            }
            if (count > 0)
                cout << "Trung binh chien dich: " << fixed << setprecision(2) << (double)sum / count << endl;
            else
                cout << "Khong co chuyen vien truyen thong nao!" << endl;
            break;
        }
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }

    } while (k != 0);

    for (int i = 0; i < tong; i++)
        delete nv[i];
    delete[] nv;

    return 0;
}
