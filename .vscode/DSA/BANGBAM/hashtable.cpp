#include <bits/stdc++.h>

using namespace std;

int m = 11;
int a[] = {10, 22, 31, 4, 15, 28, 17, 88, 59};
int n = sizeof(a) / sizeof(a[0]);

int bam(int k)
{
    return k % m;
}
int bamphu(int k)
{
    return 1 + (k % (m - 1));
}
void In(const vector<int> &bang)
{
    for (int i = 0; i < m; i++)
    {
        if (bang[i] == -1)
        {
            cout << setw(3) << "0";
        }
        else
        {
            cout << setw(3) << bang[i];
        }
        if (i != m - 1)
            cout << " |";
    }
    cout << endl;
}

void dotuyentinh()
{
    vector<int> bang(m, -1);
    cout << "Do tuyen tinh:\n";

    for (int i = 0; i < n; i++)
    {
        int k = a[i];
        int in = bam(k);
        int o_i = in;
        int step = 1;
        cout << "Them vao " << k << ": ";
        while (bang[in] != -1)
        {
            in = (o_i + step) % m;
            step++;
        }
        bang[in] = k;
        In(bang);
    }
    cout << endl;
}

void dobachai()
{
    vector<int> bang(m, -1);
    cout << "Do bac hai:\n";
    for (int i = 0; i < n; i++)
    {
        int k = a[i];
        int in = bam(k);
        int o_i = in;
        int step = 1;
        cout << "Them vao " << k << ": ";
        while (bang[in] != -1)
        {
            in = (o_i + step * step) % m;
            step++;
        }
        bang[in] = k;
        In(bang);
    }
    cout << endl;
}

void bamkep()
{
    vector<int> bang(m, -1);
    cout << "Bam kep:\n";
    for (int i = 0; i < n; i++)
    {
        int k = a[i];
        int in = bam(k);
        int o_i = in;
        int step = 1;
        cout << "Them vao " << ": ";
        while (bang[in] != -1)
        {
            in = (o_i + step * bamphu(k)) % m;
            step++;
        }
        bang[in] = k;
        In(bang);
    }
}

int main()
{
    dotuyentinh();
    dobachai();
    bamkep();

    return 0;
}