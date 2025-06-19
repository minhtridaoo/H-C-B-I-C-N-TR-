#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s;
    int count = 0;
    vector<int> v;
    v.push_back(1);
    if (n >= 2 && n <= 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }
    else if (n == 1)
    {
        cout << 1;
        return 0;
    }
    else
    {
        if (n == 4)
        {
            for (int i = 2; i <= n - (n % 2 == 0 ? 0 : 1); i += 2)
            {
                cout << i << " ";
            }
            for (int i = 1; i <= n - (n % 2 == 1 ? 0 : 1); i += 2)
            {
                cout << i << " ";
            }
        }
        else
        {
            for (int i = n - (n % 2 == 0 ? 0 : 1); i >= 2; i -= 2)
            {
                cout << i << " ";
            }

            for (int i = n - (n % 2 == 1 ? 0 : 1); i >= 1; i -= 2)
            {
                cout << i << " ";
            }
        }
    }
}