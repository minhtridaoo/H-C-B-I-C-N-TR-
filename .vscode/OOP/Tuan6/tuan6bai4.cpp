#include <bits/stdc++.h>

using namespace std;

class NhomMau
{
protected:
    string Rhesus;

public:
    void Nhap()
    {
        cout << "Nhap nhom mau Rhesus(duong hay am): ";
        cin >> Rhesus;
    }
    bool CheckRhesus()
    {
        if (Rhesus == "+")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    virtual string getTenNhomMau() = 0;
    virtual bool CheckDiTruyen(string bo, string me) = 0;
    virtual bool TuongThich(string ten, bool rhesus) = 0;
};
class NhomO : public NhomMau
{
public:
    NhomO() {}
    ~NhomO() {}
    string getTenNhomMau()
    {
        return "O";
    }
    bool CheckDiTruyen(string bo, string me)
    {
        if (bo == "A")
        {
            if (me == "AB")
            {
                return false;
            }
        }
        else if (bo == "B")
        {
            if (me == "AB")
            {
                return false;
            }
        }
        else if (bo == "AB")
        {
            return false;
        }
        else
        {
            if (me == "AB")
            {
                return false;
            }
        }
        return true;
    }
    bool TuongThich(string ten, bool rhesus) // ten của người nhận,rhesus của người nhận

    {
        if (this->CheckRhesus() == false)
        {
            return true;
        }
        if (this->CheckRhesus() == true)
        {
            if ((ten == "O" && rhesus == true) || (ten == "A" && rhesus == true) || (ten == "B" && rhesus == true) || (ten == "AB" && rhesus == true))
            {
                return true;
            }
        }
        return false;
    }
};
class NhomA : public NhomMau
{
public:
    NhomA() {}
    ~NhomA() {}
    string getTenNhomMau()
    {
        return "A";
    }
    bool CheckDiTruyen(string bo, string me)
    {
        if (bo == "B")
        {
            if (me == "B" || me == "O")
            {
                return false;
            }
        }
        else if (bo == "O")
        {
            if (me == "B" || me == "O")
            {
                return false;
            }
        }
        return true;
    }

    bool TuongThich(string ten, bool rhesus)
    {
        if (this->CheckRhesus())
        {
            if ((ten == "A" && rhesus == true) || (ten == "AB" && rhesus == true))
            {
                return true;
            }
        }
        if (this->CheckRhesus() == false)
        {
            if (ten == "A")
            {
                if (rhesus == false || rhesus == true)
                {
                    return true;
                }
            }
            else if (ten == "AB")
            {
                if (rhesus == false || rhesus == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
class NhomAB : public NhomMau
{
public:
    NhomAB() {}
    ~NhomAB() {}
    string getTenNhomMau()
    {
        return "AB";
    }
    bool CheckDiTruyen(string bo, string me)
    {
        if (bo == "A")
        {
            if (me == "A" || me == "O")
            {
                return false;
            }
        }
        else if (bo == "B")
        {
            if (me == "B" || me == "O")
            {
                return false;
            }
        }
        else if (bo == "AB")
        {
            if (me == "O")
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        return true;
    }
    bool TuongThich(string ten, bool rhesus)
    {
        if (this->CheckRhesus())
        {
            if (ten == "AB" && rhesus == true)
            {
                return true;
            }
        }
        if (!this->CheckRhesus())
        {
            if (ten == "AB")
            {
                return true;
            }
        }
        return false;
    }
};
class NhomB : public NhomMau
{
public:
    NhomB() {}
    ~NhomB() {}
    string getTenNhomMau()
    {
        return "B";
    }
    bool CheckDiTruyen(string bo, string me)
    {
        if (bo == "A")
        {
            if (me == "A" || me == "O")
            {
                return false;
            }
        }
        else if (bo == "AB")
        {
            if (me == "O")
            {
                return false;
            }
        }
        else if (bo == "O")
        {
            if (me == "A" || me == "O")
            {
                return false;
            }
        }
        return true;
    }
    bool TuongThich(string ten, bool rhesus)
    {
        if (this->CheckRhesus())
        {
            if ((ten == "B" && rhesus == true) || (ten == "AB" && rhesus == true))
            {
                return true;
            }
        }
        if (!this->CheckRhesus())
        {
            if (ten == "B")
            {
                if (rhesus == true || rhesus == false)
                {
                    return true;
                }
            }
            else if (ten == "AB")
            {
                if (rhesus == true || rhesus == false)
                {
                    return true;
                }
            }
        }
        return false;
    }
}

;
int main()
{
    NhomMau **nm = new NhomMau *[1005];
    int n;
    int tong = 0;
    int k;
    do
    {
        cout << "1.Nhập danh sách các nhóm máu của một nhóm người." << endl;
        cout << "2.Cho một bộ 3 nhóm máu của 3 người là cha, mẹ, con. Hãy kiểm tra và đưa ra kết quả nhóm máu có phù hợp với quy luật di truyền hay không?" << endl;
        cout << "3.Chọn một người X trong danh sách. Hãy liệt kê tất cả các người còn lại trong danh sách có thể cho máu người X này." << endl;
        cin >> k;
        if (k == 1)
        {
            cout << "Vui long nhap so luong nguoi: ";
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                cout << "1.Nhom A 2.Nhom B 3.Nhom O 4.Nhom AB" << endl;
                int t;
                cin >> t;
                if (t == 1)
                {
                    nm[tong] = new NhomA();
                }
                else if (t == 2)
                {
                    nm[tong] = new NhomB();
                }
                else if (t == 3)
                {
                    nm[tong] = new NhomO();
                }
                else if (t == 4)
                {
                    nm[tong] = new NhomAB();
                }
                nm[tong]->Nhap();
                tong++;
            }
        }
        else if (k == 2)
        {
            cout << "Nhap nhom mau cua bo: ";
            string bo;
            cin >> bo;
            cout << "Nhap nhom mau cua me: ";
            string me;
            cin >> me;
            cout << "Nhap nhom mau cua con: ";

            string con;
            cin >> con;
            NhomMau *nguoicon;
            if (con == "A")
            {
                nguoicon = new NhomA();
            }
            else if (con == "B")
            {
                nguoicon = new NhomB();
            }
            else if (con == "AB")
            {
                nguoicon = new NhomAB();
            }
            else if (con == "O")
            {
                nguoicon = new NhomO();
            }
            else
            {
                cout << "Nhom mau khong hop le " << endl;
                continue;
            }
            if (nguoicon->CheckDiTruyen(bo, me))
            {
                cout << "Dung" << endl;
            }
            else
            {
                cout << "Nguoi me cheating !!!!!!!" << endl;
            }
        }
        else if (k == 3)
        {
            cout << "Chon nguoi trong danh sach " << endl;
            int k;
            cin >> k;
            cout << "So nguoi co the cho mau nguoi X la:" << endl;
            if (k <= (tong - 1))
            {
                for (int i = 0; i < tong; i++)
                {
                    if (i != k && nm[i]->TuongThich(nm[k]->getTenNhomMau(), nm[k]->CheckRhesus()))
                    {
                        cout << "Nguoi thu " << i + 1 << " ";
                    }
                }
            }
            else
            {
                cout << "Khong co nguoi nao thoa man" << endl;
                continue;
            }
        }

    } while (k != 0);

    return 0;
    //HK2, NH 2017-2018
}