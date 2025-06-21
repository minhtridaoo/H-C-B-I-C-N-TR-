#include <bits/stdc++.h>

using namespace std;

// Tom tat de bai
// Dat dai: dat nong nghiep va dat phi nong nghiep
// Dat nong nghiep: Sogiaychungnhan 1 , nguoi so huu 2 ,so thua dat 3 so to ban do4 ,
// dia chi thua dat 5 , dien tich 6 , thoi gian su dung ,ngay cap 7 , don gia thue 8
// Dat phi nong nghiep:Sogiaychungnhan 1 ,nguoi sohuu dat 2, so thua dat 3 ,so to ban do 4 ,dia chi thua dat 5 , dientich 6
// ngay cap 7 ,don gia thue 8
//
class Nguoi
{
private:
    string HoTen;
    int NamSinh;
    string CMND;
    string DiaChi;

public:
    Nguoi() {}
    ~Nguoi() {}
    void Nhap()
    {
        cout << "Ho ten: ";
        cin.ignore();
        getline(cin, HoTen);
        cout << "Nam sinh: ";
        cin >> NamSinh;
        cout << "CMND: ";
        cin >> CMND;
        cout << "Dia chi: ";
        cin.ignore();
        getline(cin, DiaChi);
    }
    void Xuat()
    {
        cout << "Ho ten: " << HoTen << endl;
        cout << "Nam sinh: " << NamSinh << endl;
        cout << "CMND: " << CMND << endl;
        cout << "Dia chi: " << DiaChi << endl;
    }
};
class Ngay
{
private:
    int ngay, thang, nam;

public:
    Ngay() {}
    ~Ngay() {}
    void Nhap()
    {
        cout << "Ngay: ";
        cin >> ngay;
        cout << "Thang: ";
        cin >> thang;
        cout << "Nam: ";
        cin >> nam;
    }
    void Xuat()
    {
        cout << ngay << "/" << thang << "/" << nam << endl;
    }
};
class DatDai
{
protected:
    string SoGiayChungNhan;
    Nguoi ng;
    long long SoThuaDat;
    long long SoToBanDo;
    string DiaChiThuaDat;
    double DienTich;
    Ngay NgayCap;
    long long DonGiaThue;

public:
    DatDai() {}
    ~DatDai() {}
    virtual void Nhap()
    {
        cout << "So giay chung nhan: ";
        cin >> SoGiayChungNhan;
        ng.Nhap();
        cout << "So thua dat: ";
        cin >> SoThuaDat;
        cout << "So to ban do: ";
        cin >> SoToBanDo;
        cout << "Dia chi thua dat: ";
        cin.ignore();
        getline(cin, DiaChiThuaDat);
        cout << "Dien tich: ";
        cin >> DienTich;
        NgayCap.Nhap();
        cout << "Don gia thue: ";
        cin >> DonGiaThue;
    }
    virtual void Xuat()
    {
        cout << "So giay chung nhan: " << SoGiayChungNhan << endl;
        ng.Xuat();
        cout << "So thua dat: " << SoThuaDat << endl;
        cout << "So to ban do: " << SoToBanDo << endl;
        cout << "Dia chi thua dat: " << DiaChiThuaDat << endl;
        cout << "Dien tich: " << DienTich << endl;
        NgayCap.Xuat();
        cout << "Don gia thue: " << DonGiaThue << endl;
    }
    long long GiaThue()
    {
        return DienTich * DonGiaThue;
    }
    virtual bool HetHSD() = 0;
};
class DatNongNghiep : public DatDai
{
private:
    int ThGianSD;

public:
    void Nhap()
    {
        DatDai::Nhap();
        cout << "Thoi gian su dung: ";
        cin >> ThGianSD;
    }
    void Xuat()
    {
        DatDai::Xuat();
        cout << "Thoi gian su dung: " << ThGianSD << endl;
    }
    bool HetHSD()
    {
        if (ThGianSD < 2025)
        {
            return true;
        }
        return false;
    }
};
class DatPhiNongNghiep : public DatDai
{
public:
    bool HetHSD()
    {
        return 0;
    }
};

int main()
{
    DatDai **dd = new DatDai *[1000];
    int n;
    cout << "Nhap so luong dat: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "1.Nong Nghiep 2.Phi nong nghiep" << endl;
        int c;
        cin >> c;
        if (c == 1)
        {
            dd[i] = new DatNongNghiep();
        }
        else if (c == 2)
        {
            dd[i] = new DatPhiNongNghiep();
        }
        dd[i]->Nhap();
    }
    cout << "Thua dat co tien thue phong dong nhieu nhat la: " << endl;
    int max1 = INT_MIN;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (dd[i]->GiaThue() > max1)
        {
            max1 = dd[i]->GiaThue();
            t = i;
        }
    }
    dd[t]->Xuat();
    cout << "Cac thua dat nong nghiep da het thoi han su dung: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (dd[i]->HetHSD())
        {
            dd[i]->Xuat();
        }
    }
    for (int i = 0; i < n; i++)
    {
        delete dd[i];
    }
    delete[] dd;
}