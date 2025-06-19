#include <bits/stdc++.h>
using namespace std;

class GiaoDich
{
protected:
    string MaGiaoDich;
    string NgayGiaoDich;
    long long DienTich;
    double DonGia;

public:
    GiaoDich(string MaGiaoDich = "", string NgayGiaoDich = "", long long DienTich = 0, double DonGia = 0)
        : MaGiaoDich(MaGiaoDich), NgayGiaoDich(NgayGiaoDich), DienTich(DienTich), DonGia(DonGia) {}

    void Nhap()
    {
        cout << "Vui long dien thong tin" << endl;
        cout << "Ma giao dich: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, MaGiaoDich);
        cout << "Ngay giao dich (dd/mm/yyyy): ";
        getline(cin, NgayGiaoDich);
        cout << "Dien tich: ";
        cin >> DienTich;
        cout << "Don gia: ";
        cin >> DonGia;
    }

    void Xuat() const
    {
        cout << "Thong tin giao dich: " << endl;
        cout << "Ma giao dich: " << MaGiaoDich << endl;
        cout << "Ngay giao dich: " << NgayGiaoDich << endl;
        cout << "Dien tich: " << DienTich << endl;
        cout << "Don gia: " << DonGia << endl;
    }

    string getNgayGiaoDich() const
    {
        return NgayGiaoDich;
    }
};

class GiaoDichDat : public GiaoDich
{
protected:
    string LoaiDat;

public:
    GiaoDichDat(string MaGiaoDich = "", string NgayGiaoDich = "", long long DienTich = 0, double DonGia = 0, string LoaiDat = "")
        : GiaoDich(MaGiaoDich, NgayGiaoDich, DienTich, DonGia), LoaiDat(LoaiDat) {}

    void NhapThongTin()
    {
        GiaoDich::Nhap();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Loai dat: ";
        getline(cin, LoaiDat);
    }

    void XuatThongTin() const
    {
        GiaoDich::Xuat();
        cout << "Loai dat: " << LoaiDat << endl;
        cout << "Gia can nha: " << GiaLoaiDat() << endl;
    }

    double GiaLoaiDat() const
    {
        if (LoaiDat == "A")
            return DienTich * DonGia * 1.5;
        if (LoaiDat == "B" || LoaiDat == "C")
            return DienTich * DonGia;
        return 0;
    }
};

class GiaoDichNhaPho : public GiaoDich
{
protected:
    string LoaiNha;
    string DiaChi;

public:
    GiaoDichNhaPho(string MaGiaoDich = "", string NgayGiaoDich = "", long long DienTich = 0, double DonGia = 0, string LoaiNha = "", string DiaChi = "")
        : GiaoDich(MaGiaoDich, NgayGiaoDich, DienTich, DonGia), LoaiNha(LoaiNha), DiaChi(DiaChi) {}

    void NhapThongTin()
    {
        GiaoDich::Nhap();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Loai nha: ";
        getline(cin, LoaiNha);
        cout << "Dia chi: ";
        getline(cin, DiaChi);
    }

    void XuatThongTin() const
    {
        GiaoDich::Xuat();
        cout << "Loai nha: " << LoaiNha << endl;
        cout << "Dia chi: " << DiaChi << endl;
        cout << "Gia can nha: " << GiaLoaiNha() << endl;
    }

    double GiaLoaiNha() const
    {
        if (LoaiNha == "caocap")
            return DienTich * DonGia;
        if (LoaiNha == "thuong")
            return DienTich * DonGia * 0.9;
        return 0;
    }
};

class GiaoDichCanHoChungCu : public GiaoDich
{
protected:
    string MaCan;
    int ViTriCan;

public:
    GiaoDichCanHoChungCu(string MaGiaoDich = "", string NgayGiaoDich = "", long long DienTich = 0, double DonGia = 0, string MaCan = "", int ViTriCan = 0)
        : GiaoDich(MaGiaoDich, NgayGiaoDich, DienTich, DonGia), MaCan(MaCan), ViTriCan(ViTriCan) {}

    void NhapThongTin()
    {
        Nhap();
        cout << "Vi tri can: ";
        cin >> ViTriCan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ma can: ";
        getline(cin, MaCan);
    }

    void XuatThongTin() const
    {
        GiaoDich::Xuat();
        cout << "Vi tri can: " << ViTriCan << endl;
        cout << "Ma can: " << MaCan << endl;
        cout << "Gia can nha: " << GiaViTriCan() << endl;
    }

    double GiaViTriCan() const
    {
        if (ViTriCan == 1)
            return DienTich * DonGia * 2;
        if (ViTriCan >= 15)
            return DienTich * DonGia * 1.2;
        return DienTich * DonGia;
    }
};

int main()
{
    vector<GiaoDichDat> dsnhadat;
    vector<GiaoDichCanHoChungCu> dschungcu;
    vector<GiaoDichNhaPho> dsnhapho;
    int n;
    do
    {
        cout << "\n--------------------MENU--------------------" << endl;
        cout << "1. Nhap giao dich nha dat" << endl;
        cout << "2. Nhap giao dich nha pho" << endl;
        cout << "3. Nhap giao dich can ho chung cu" << endl;
        cout << "4. Tong so luong tung loai giao dich" << endl;
        cout << "5. Trung binh thanh tien can ho chung cu" << endl;
        cout << "6. Giao dich nha pho co gia tri cao nhat" << endl;
        cout << "7. Danh sach giao dich thang 12 nam 2024" << endl;
        cout << "0. Thoat" << endl;
        cout << "Lua chon: ";
        cin >> n;

        if (n == 1)
        {
            int k;
            cout << "Nhap so giao dich: ";
            cin >> k;
            for (int i = 0; i < k; ++i)
            {
                GiaoDichDat gd;
                gd.NhapThongTin();
                dsnhadat.push_back(gd);
            }
        }
        else if (n == 2)
        {
            int k;
            cout << "Nhap so giao dich: ";
            cin >> k;
            for (int i = 0; i < k; ++i)
            {
                GiaoDichNhaPho gd;
                gd.NhapThongTin();
                dsnhapho.push_back(gd);
            }
        }
        else if (n == 3)
        {
            int k;
            cout << "Nhap so giao dich: ";
            cin >> k;
            for (int i = 0; i < k; ++i)
            {
                GiaoDichCanHoChungCu gd;
                gd.NhapThongTin();
                dschungcu.push_back(gd);
            }
        }
        else if (n == 4)
        {
            cout << "Nha dat: " << dsnhadat.size() << endl;
            cout << "Nha pho: " << dsnhapho.size() << endl;
            cout << "Can ho chung cu: " << dschungcu.size() << endl;
        }
        else if (n == 5)
        {
            double tong = 0;
            for (auto &gd : dschungcu)
            {
                tong += gd.GiaViTriCan();
            }
            if (!dschungcu.empty())
                cout << "Trung binh thanh tien: " << tong / dschungcu.size() << endl;
            else
                cout << "Khong co giao dich nao." << endl;
        }
        else if (n == 6)
        {
            double maxGia = -1;
            GiaoDichNhaPho maxGD;
            for (auto &gd : dsnhapho)
            {
                if (gd.GiaLoaiNha() > maxGia)
                {
                    maxGia = gd.GiaLoaiNha();
                    maxGD = gd;
                }
            }
            cout << "Giao dich co gia cao nhat:\n";
            maxGD.XuatThongTin();
        }
        else if (n == 7)
        {
            cout << "Giao dich thang 12/2024:\n";
            for (auto &gd : dsnhadat)
            {
                if (gd.getNgayGiaoDich().substr(3, 2) == "12" && gd.getNgayGiaoDich().substr(6, 4) == "2024")
                    gd.XuatThongTin();
            }
            for (auto &gd : dsnhapho)
            {
                if (gd.getNgayGiaoDich().substr(3, 2) == "12" && gd.getNgayGiaoDich().substr(6, 4) == "2024")
                    gd.XuatThongTin();
            }
            for (auto &gd : dschungcu)
            {
                if (gd.getNgayGiaoDich().substr(3, 2) == "12" && gd.getNgayGiaoDich().substr(6, 4) == "2024")
                    gd.XuatThongTin();
            }
        }
    } while (n != 0);

    return 0;
}
