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
    GiaoDich(string MaGiaoDich = "", string NgayGiaoDich = "", long long DienTich = 0, double DonGia = 0) : MaGiaoDich(MaGiaoDich), NgayGiaoDich(NgayGiaoDich), DienTich(DienTich), DonGia(DonGia) {}
    virtual void Nhap()
    {

        cout << "Ma giao dich: ";
        cin >> MaGiaoDich;
        cin.ignore();
        cout << "Ngay giao dich: ";
        cin >> NgayGiaoDich;
        cin.ignore();
        cout << "Dien tich: ";
        cin >> DienTich;
        cin.ignore();
        cout << "Don gia: ";
        cin >> DonGia;
        cin.ignore();
    }
    virtual void Xuat()
    {
        cout << "Ma giao dich: " << MaGiaoDich << endl;
        cout << "Ngay giao dich: " << NgayGiaoDich << endl;
        cout << "Dien tich: " << DienTich << endl;
        cout << "Don gia: " << DonGia << endl;
    }
    virtual double ThanhTien() = 0;
    virtual int PhanLoai() = 0;
    virtual ~GiaoDich() {}
};

class GiaoDichNhaDat : public GiaoDich
{
private:
    string LoaiDat;

public:
    void Nhap()
    {
        GiaoDich::Nhap();
        cout << "Loai dat: ";
        cin >> LoaiDat;
    }
    void Xuat()
    {
        GiaoDich::Xuat();
        cout << "Loai dat: " << LoaiDat << endl;
        cout << "Gia loai dat: " << ThanhTien() << endl;
    }
    double ThanhTien() override
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
    int PhanLoai()
    {
        return 1;
    }
};

class GiaoDichNhaPho : public GiaoDich
{
private:
    string LoaiNha;
    string DiaChi;

public:
    void Nhap()
    {
        GiaoDich::Nhap();
        cout << "Loai nha: ";
        cin >> LoaiNha;
        cin.ignore();
        cout << "Dia chi: ";
        getline(cin, DiaChi);
    }
    void Xuat()
    {
        GiaoDich::Xuat();

        cout << "Loai nha: " << LoaiNha << endl;

        cout << "Dia chi: " << DiaChi << endl;
        cout << "Gia can nha: " << ThanhTien() << endl;
    }
    double ThanhTien() override
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
    int PhanLoai()
    {
        return 2;
    }
};
class GiaoDichNhaChungCu : public GiaoDich
{
private:
    string MaCan;
    int ViTriCan;

public:
    void Nhap()
    {
        GiaoDich::Nhap();
        cout << "Ma can: ";
        cin >> MaCan;
        cout << "Vi tri can: ";
        cin >> ViTriCan;
    }
    void Xuat()
    {
        GiaoDich::Xuat();
        cout << "Ma can: " << MaCan << endl;
        cout << "Vi tri can: " << ViTriCan << endl;
        cout << "Gia tri can nha: " << ThanhTien() << endl;
    }
    double ThanhTien() override
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
    int PhanLoai()
    {
        return 3;
    }
};

int main()
{
    int c;

    GiaoDich **ds = new GiaoDich *[1000];
    int countdat = 0;
    int countpho = 0;
    int n;
    int countchungcu = 0;
    int tong = 0;
    do

    {
        cout << "-------MENU----------" << endl;
        cout << "1.Nhap danh sach cac giao dich" << endl;
        cout << "2.Tinh tong so luong cho tung loai" << endl;
        cout << "3.Tinh trung binh thanh tien cua giao dich can ho chung cu" << endl;
        cout << "4.Cho biet giao dich nha Pho co gia tri cao nhat" << endl;
        cout << "0.Thoat" << endl;
        cin >> c;

        if (c == 1)
        {

            cout << "Nhap so luong giao dich: ";
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                cout << "Chon loai giao dich:" << endl;
                cout << "1.Nha dat" << endl;
                cout << "2.Nha pho" << endl;
                cout << "3.Nha chung cu" << endl;
                int k;
                cin >> k;
                if (k == 1)
                {
                    ds[tong] = new GiaoDichNhaDat();
                    ds[tong]->Nhap();
                    countdat++;
                }
                else if (k == 2)
                {
                    ds[tong] = new GiaoDichNhaPho();
                    ds[tong]->Nhap();
                    countpho++;
                }
                else if (k == 3)
                {
                    ds[tong] = new GiaoDichNhaChungCu();
                    ds[tong]->Nhap();
                    countchungcu++;
                }
                tong++;
            }
        }
        else if (c == 2)
        {
            cout << "So luong nha Dat la: " << countdat << endl;
            cout << "So luong nha Pho la :" << countpho << endl;
            cout << "So luong nha chung cu la: " << countchungcu << endl;
        }
        else if (c == 3)
        {
            long long sum = 0;
            for (int i = 0; i < tong; i++)
            {
                if (ds[i]->PhanLoai() == 3)
                {
                    sum += ds[i]->ThanhTien();
                }
            }
            if (countchungcu == 0)
            {
                cout << "Chua co giao dich nao" << endl;
            }
            else
            {
                cout << "Gia tri trung binh la: " << (double)sum / countchungcu << endl;
            }
        }
        else if (c == 4)
        {
            int max1 = INT_MIN;
            for (int i = 0; i < tong; i++)
            {
                if (ds[i]->PhanLoai() == 2)
                {
                    if (ds[i]->ThanhTien() > max1)
                    {
                        max1 = ds[i]->ThanhTien();
                    }
                }
            }
            if (countpho != 0)
            {
                cout << max1 << endl;
            }
            else
            {
                cout << "Chua co giao dich nao" << endl;
            }
        }

    } while (c != 0);
}