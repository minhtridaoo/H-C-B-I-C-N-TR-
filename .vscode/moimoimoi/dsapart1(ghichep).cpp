#include <bits/stdc++.h>

using namespace std;

#define ll long long;

void pt(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }
}
int gcd1(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int gcd2(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return a + b;
    }
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}
int lcm1(int a, int b)
{
    return a * b / gcd1(a, b);
}
int lcm2(int a, int b)
{
    return a * b / gcd2(a, b);
}
void dongduchotongsohang()
{
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res + a[i] % k;
        res %= k;
    }
    cout << res << endl;
}

void dongduchotichsohang()
{
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res * a[i] % k;
        res %= k;
    }
    cout << res << endl;
}
void dongduchomusohang()
{ // binh thuong se chi la (a^b)%c thui
    int n;
    cin >> n;
    int a[1000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int res = 0;
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        res = res ^ a[i] % k;
        res %= k;
    }
}
// quyhoachdongtimsofibonaccithun
long long hamfibolonglong(int n)
{
    cin >> n;
    long long f[n + 1];
    f[0] = 0;
    f[1] = 1;
    int k;
    cin >> k;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        f[i] %= k;
    }
    return f[n] % k;
}

long long hamfibo(int n) // hamchiapdungvoisofibothu93
{
    long long f[n + 1];
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

// binary exponentiation(luy thuy nhi phan)
long long binpow(long long a, long long b)
{
    if (b == 0)
        return a;
    long long x = binpow(a, b / 2);
    if (b % 2 == 1)
    {
        return x * x * a;
    }
    else
        return x * x;
}

long long binpow2(long long a, long long b)
{

    long long res = 1;
    while (b != 0)
    {
        if (b % 2 == 1)
        {
            res *= a;
        }
        b /= 2;
        a *= a;
    }

    return res;
}
// Gỉa sử với số 13 phân tích thành số nhị phân như sau:
// 13/2=6 dư 1
// 6/2=3 dư 0
// 3/2=1 dư 1
// 1/2=1 dư 1 -> 1101(*lấy từ dưới lên trên)
// Gỉa sử với dãy số 1011 thì thành: 1*2^3+0*2^2+1*2^1+1*2^0=8+2+1=11
// Từ đó suy ra ->a^13=a^8*a^4*a

// pow( 2,22 )=10110=a^16*a^4*a^2

//(bymyself)
void phantichsonhiphan()
{
    int n;
    cin >> n;
    int temp;
    int du;
    int a[n], b[n];
    int res1 = 0, res2 = 0;
    while (n > 0)
    {
        temp = n / 2; // temp0=6(luc nay n vx=13);->temp1=3
        du = n % 2;   // du0=1,du1=0
        temp = n;     // n0=6
        if (temp)
        {
            a[res1] = temp;
            res1++;
        }
        if (du)
        {
            b[res2] = du;
            res2++;
        }
    }
    for (int i = 0; i < res1; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int j = res2 - 1; j >= 0; j--)
    {
        cout << b[j] << " ";
    }
}

// Công thức Ckn=n!/(k!*(n-k)!)
long long nCk(int n, int k)
{
    long long res = 1;
    cin >> n;
    cin >> k;

    k = min(k, n - k);
    for (int i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= i + 1;
    }
    return res;
}

// Buổi 2:(chữa bài tập lý thuyết buổi 1 )
const int maxn = 100000;
bool nt[maxn / +1];
void sang()
{
    for (int i = 0; i <= maxn; i++)
    {
        nt[i] = true;
    }
    nt[0] = nt[1] = false;
    for (int i = 2; i <= sqrt(maxn); i++)
    {
        if (nt[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                nt[j] = false;
            }
        }
    }
}

int main()
{
    phantichsonhiphan();
}



//bai2:timkiemnhiphan:
#include <bits/stdc++.h>

using namespace std;

int Find_x(vector<int> x, int n, int k)
{
    int i = 0;

    while (i < n)
    {
        if (x[i] == k)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int Find_x1(vector<int> x, int n, int k)
{
    int i = 0;
    x[n] = k;
    while (x[i] != k)
    {
        i++;
    }
    if (i < n)
        return i;
    else
        return -1;
}

int binary_search(vector<int> v, int l, int r, int k)
{
    if (l > r)
    {
        return -1;
    }
    int mid = l + (r - l) / 2;
    if (v[mid] == k)
    {
        return mid;
    }
    if (v[mid] < k)
    {
        return binary_search(v, mid + 1, l, k);
    }
    else
    {
        return binary_search(v, l, mid - 1, k);
    }
}

int binary_search_rervese(vector<int> v, int l, int r, int k)
{
    while (l <= r)
    {
        int m = l + ((r - l) * (k - v[l])) / (v[r] - v[l]);
        if (v[m] == k)
        {
            return m;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;
    sort(v.begin(), v.end());
    cout << binary_search(v, 0, n - 1, k);
    cout << binary_search_rervese(v, 0, n - 1, k);
}

//(TO CHUC VA CAU TRUC MAY TINH II : BAI TAP VE CHUYEN DOI CO SO )
#include <iostream>
using namespace std;

// Chuyển đổi từ số thập phân sang nhị phân
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        cout << 0;
        return;
    }
    int binary[32], i = 0;
    while (decimal > 0) {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << binary[j];
    }
}

// Chuyển đổi từ số thập phân sang thập lục phân
void decimalToHex(int decimal) {
    if (decimal == 0) {
        cout << 0;
        return;
    }
    char hexDigits[] = "0123456789ABCDEF";
    char hex[32];
    int i = 0;
    while (decimal > 0) {
        hex[i++] = hexDigits[decimal % 16];
        decimal /= 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << hex[j];
    }
}

// Chuyển đổi từ số nhị phân sang số thập phân
int binaryToDecimal(int binary) {
    int decimal = 0, base = 1;
    while (binary > 0) {
        decimal += (binary % 10) * base;
        binary /= 10;
        base *= 2;
    }
    return decimal;
}

// Chuyển đổi từ số thập lục phân sang số thập phân
int hexToDecimal(string hexStr) {
    int decimal = 0, base = 1;
    int length = hexStr.size();
    for (int i = length - 1; i >= 0; i--) {
        if (hexStr[i] >= '0' && hexStr[i] <= '9') {
            decimal += (hexStr[i] - '0') * base;
        } else if (hexStr[i] >= 'A' && hexStr[i] <= 'F') {
            decimal += (hexStr[i] - 'A' + 10) * base;
        }
        base *= 16;
    }
    return decimal;
}

int main() {
    int choice;
    cout << "Chọn kiểu chuyển đổi:\n";
    cout << "1. Thập phân -> Nhị phân\n";
    cout << "2. Thập phân -> Thập lục phân\n";
    cout << "3. Nhị phân -> Thập phân\n";
    cout << "4. Thập lục phân -> Thập phân\n";
    cout << "Nhập lựa chọn: ";
    cin >> choice;
    
    if (choice == 1) {
        int decimal;
        cout << "Nhập số thập phân: ";
        cin >> decimal;
        decimalToBinary(decimal);
        cout << endl;
    } else if (choice == 2) {
        int decimal;
        cout << "Nhập số thập phân: ";
        cin >> decimal;
        decimalToHex(decimal);
        cout << endl;
    } else if (choice == 3) {
        int binary;
        cout << "Nhập số nhị phân: ";
        cin >> binary;
        cout << "Số thập phân: " << binaryToDecimal(binary) << endl;
    } else if (choice == 4) {
        string hexStr;
        cout << "Nhập số thập lục phân: ";
        cin >> hexStr;
        cout << "Số thập phân: " << hexToDecimal(hexStr) << endl;
    } else {    
        cout << "Lựa chọn không hợp lệ!" << endl;
    }
    
    return 0;
}

//BAI TOAN MANG 2 CHIEU LOANG  NHI PHAN 
#include <bits/stdc++.h>

using namespace std;
int a[500][500];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int n;
int m;
void loang(int i, int j)
{
    a[i][j] = 0;
    for (int q = 0; q < 4; q++)
    {
        int i1 = i + dx[q];
        int j1 = j + dy[q];
        if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1])
        {
            loang(i1, j1);
        }
    }
}

int main()
{

    cin >> n;

    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)

    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j])
            {
                cnt++;
                loang(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}

