#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> mp;
set<string> se;

void add(string u, string v)
{
    mp[u].push_back(v);
    mp[v].push_back(u);
    se.insert(u);
    se.insert(v);
}
void input()
{
    int c;
    cin >> c;
    string u, v;
    for (int i = 0; i < c; i++)
    {
        cin >> u >> v;
        add(u, v);
    }
}
void output()
{ //danh sach ke( luu y phai nho)
    for (auto &it : mp)
    {
        cout << it.first << ": ";
        for (string &i : it.second)
        {
            cout << i << " ";
        }
        cout << endl;
        
    }
}



int main()
{
    input();
    output();
}

