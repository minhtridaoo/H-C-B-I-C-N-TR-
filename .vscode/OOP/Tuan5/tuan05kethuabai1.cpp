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
    {
        this->MaGiaoDich = MaGiaoDich;
        this->NgayGiaoDich = NgayGiaoDich;
        this->DienTich = DienTich;
        this->DonGia = DonGia;
    }
    void Nhap()
    {
        cout << "Vui long dien thong tin" << endl;
        cout << " Ma giao dich: ";
        cin >> MaGiaoDich;
        cout << "Ngay giao dich:";
        cin >> NgayGiaoDich;
        cout << "Dien tich: ";
        ;
        cin >> DienTich;
        cout << "Don gia: ";
        cin >> DonGia;
    }
    void Xuat()
    {
        cout << "Thong tin giao dich: " << endl;
        cout << "Ma giao dich: " << MaGiaoDich << endl;
        cout << "Ngay giao dich: " << NgayGiaoDich << endl;
        cout << "Dien tich: " << DienTich << endl;
        cout << "Don gia: " << DonGia << endl;
    }
    string getNgayGiaoDich()
    {
        return NgayGiaoDich;
    }
    
};

class GiaoDichDat : public GiaoDich
{
protected:
    string LoaiDat;

public:
    GiaoDichDat(string MagGiaoDich = "", string NgayGiaoDich = "", long long DienTich = 0, double DonGia = 0, string LoaiDat = "")
    {
        this->MaGiaoDich = MagGiaoDich;
        this->NgayGiaoDich = NgayGiaoDich;
        this->DienTich = DienTich;
        this->DonGia = DonGia;
        this->LoaiDat = LoaiDat;
    }

    void NhapThongTin()
    {
        GiaoDich::Nhap();
        cout << "Loai dat:";
        cin >> LoaiDat;
    }
    void XuatThongTin()
    {
        GiaoDich::Xuat();
        cout << "Loai dat: " << LoaiDat << endl;
        cout << "Gia can nha: " << GiaLoaiDat() << endl;
    }
    long long GiaLoaiDat()
    {
        if (LoaiDat == "A")
        {
            return DienTich * DonGia * 1.5;
        }
        if (LoaiDat == "B" || LoaiDat == "C")
        {
            return DienTich * DonGia;
        }
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
    {
        this->MaGiaoDich = MaGiaoDich;
        this->NgayGiaoDich = NgayGiaoDich;
        this->DienTich = DienTich;
        this->DonGia = DonGia;
        this->LoaiNha = LoaiNha;
        this->DiaChi = DiaChi;
    }
    void NhapThongTin()
    {

        Nhap();
        cout << "Loai nha: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, LoaiNha);

        cout << "Dia chi: ";
        getline(cin, DiaChi);
    }
    void XuatThongTin()
    {
        Xuat();
        cout << "Loai nha: " << LoaiNha << endl;
        cout << "Dia chi: " << DiaChi << endl;
        cout << "Gia can nha: " << GiaLoaiNha() << endl;
    }
    long long GiaLoaiNha()
    {
        if (LoaiNha == "caocap")
        {
            return DienTich * DonGia;
        }
        if (LoaiNha == "thuong")
        {
            return DienTich * DonGia * 0.9;
        }
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
    {
        this->MaGiaoDich = MaGiaoDich;
        this->NgayGiaoDich = NgayGiaoDich;
        this->DienTich = DienTich;
        this->DonGia = DonGia;
        this->ViTriCan = ViTriCan;
        this->MaCan = MaCan;
    }
    void NhapThongTin()
    {
        Nhap();
        cout << "Vi tri can:";
        cin >> ViTriCan;
        cout << "Ma can: ";
        cin >> MaCan;
    }

    void XuatThongTin()
    {
        Xuat();
        cout << "Vi tri can: " << ViTriCan << endl;
        cout << "Ma can: " << MaCan << endl;
        cout << "Gia can nha: " << GiaViTriCan() << endl;
    }
    int GiaViTriCan()
    {
        if (ViTriCan == 1)
        {
            return DienTich * DonGia * 2;
        }
        else if (ViTriCan >= 15)
        {
            return DienTich * DonGia * 1.2;
        }
        else
        {
            return DienTich * DonGia;
        }
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
        cout << "--------------------MENU--------------------" << endl;
        cout << "1.Nhap danh sach cac giao dich nha Dat" << endl;
        cout << "2.Nhap danh sach cac giao dich nha Pho" << endl;
        cout << "3.Nhap danh sach cac giao dich nha chung cu" << endl;
        cout << "4.Tinh tong so luong cho tung loai" << endl;
        cout << "5.Tinh trung binh thanh tien cua giao dich Can ho chung cu " << endl;
        cout << "6.Cho biet Giao dich Nha pho co tri gia cao nhat (thanh tien)" << endl;
        cout << "7.Xuat ra danh sach cac giao dich cua thang 12 nam 2024." << endl;
        cout << "0.Thoat" << endl;
        cout << "Moi ban chon: ";
        cin >> n;

        if (n == 1)
        {
            int k;

            cout << "Ban muon nhap bao nhieu giao dich ? ";
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                GiaoDichDat a;
                a.NhapThongTin();
                dsnhadat.push_back(a);
            }
        }
        else if (n == 2)
        {
            int k;
            cout << "Ban muon nhap bao nhieu giao dich ?";
            cin >> k;
            for (int i = 0; i < k; i++)
            {
                GiaoDichNhaPho a;
                a.NhapThongTin();
                dsnhapho.push_back(a);
            }
        }
        else if (n == 3)
        {
            int k;
            cout << "Ban muon nhap bao nhieu giao dich ?";
            cin >> k;
            for (int i = 0; i < k; i++)
            {

                GiaoDichCanHoChungCu A;
                A.NhapThongTin();
                dschungcu.push_back(A);
            }
        }
        else if (n == 4)
        {
            int nhadat = 0;
            int nhapho = 0;
            int nhachungcu = 0;
            for (auto it : dschungcu)
            {
                nhachungcu++;
            }
            for (auto it : dsnhadat)
            {
                nhadat++;
            }
            for (auto it : dsnhapho)
            {
                nhapho++;
            }
            cout << "So luong giao dich nha pho: " << nhapho << endl;
            cout << "So luong giao dich nha dat: " << nhadat << endl;
            cout << "So luong giao dich nha chung cu: " << nhachungcu << endl;
        }
        else if (n == 5)
        {
            double tong = 0;
            int count = 0;
            for (auto it : dschungcu)
            {
                tong += it.GiaViTriCan();
                count++;
            }

            if (count != 0)
            {
                cout << "Trung binh giao dich chung cu do la: " << (double)tong / count << endl;
            }
            else
            {
                cout << "Khong co giao dich nao" << endl;
            }
        }
        else if (n == 6)
        {
            int max1 = INT_MIN;
            for (auto it : dsnhapho)
            {
                if (it.GiaLoaiNha() > max1)
                {
                    max1 = it.GiaLoaiNha();
                }
            }
            cout << "Giao dich nha pho co gia tri cao nhat la: " << max1 << endl;
        }
        else if (n == 7)
        {
            cout << "Danh sach cua cac giao dich cua thang 12 nam 2024" << endl;
            for (auto it : dschungcu)
            {
                string thang = it.getNgayGiaoDich().substr(3, 2);
                string nam = it.getNgayGiaoDich().substr(6, 4);
                if (it.getNgayGiaoDich().length() >= 10)
                {

                    if (thang == "12" && nam == "2024")
                    {
                        it.XuatThongTin();
                    }
                }
            }
            for (auto it : dsnhadat)
            {
                string thang = it.getNgayGiaoDich().substr(3, 2);
                string nam = it.getNgayGiaoDich().substr(6, 4);
                if (it.getNgayGiaoDich().length() >= 10)
                {
                    if (thang == "12" && nam == "2024")
                    {
                        it.XuatThongTin();
                    }
                }
            }
            for (auto it : dsnhapho)
            {
                string thang = it.getNgayGiaoDich().substr(3, 2);
                string nam = it.getNgayGiaoDich().substr(6, 4);
                if (it.getNgayGiaoDich().length() >= 10)
                {
                    if (thang == "12" && nam == "2024")
                    {
                        it.XuatThongTin();
                    }
                }
            }
        }
    } while (n != 0);
}