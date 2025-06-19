#include <bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h>

using namespace std;
void merge(vector<int> &v, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> trai(n1), phai(n2);
    for (int i = 0; i < n1; i++)
    {
        trai[i] = v[l + i];
    }
    for (int i = 0; i < n2; i++)
    {

        phai[i] = v[i + 1 + m];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (trai[i] <= phai[j])
        {
            v[k] = trai[i];
            i++;
        }
        else
        {
            v[k] = phai[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        v[k] = trai[i];
        i++;
        k++;
    }
    while (j < n2)
    {

        v[k] = phai[j];
        j++;
        k++;
    }
}
void mergesort(vector<int> &v, int l, int r)
{
    if (l < r)
    {

        int mid = l + (r - l) / 2;
        mergesort(v, l, mid);
        mergesort(v, mid + 1, r);
        merge(v, l, mid, r);
    }
}
void selectionsort(vector<int> a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        bool found = false;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[index])
            {
                index = j;
                found = true    ;
            }
        }
        swap(a[i], a[index]);

        cout << "Buoc " << i + 1 << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}
void insertionsort(vector<int> a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = key;
        cout << "Buoc " << i << ": ";
        for (int k = 0; k < n; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}
void bubblesort(vector<int> v, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                
            }
        }cout << "Buoc " << i+1 << ": ";
        for (int i = 0; i < n; i++)
        {

            cout << v[i] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> dem;
    set<int> se;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];

        se.insert(v[i]);
        mp[v[i]]++;
    }
    bubblesort(v, n);
} // Hàm phân chia (partition)
int partition(vector<int> &v, int low, int high)
{
    int pivot = v[high]; // chọn phần tử cuối làm pivot
    int i = low - 1;     // chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1; // trả về vị trí đúng của pivot
}

// Hàm quick sort chính
void quickSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int pi = partition(v, low, high);

        quickSort(v, low, pi - 1);  // sắp xếp bên trái pivot
        quickSort(v, pi + 1, high); // sắp xếp bên phải pivot
    }
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
    selectionsort(v, n);
}