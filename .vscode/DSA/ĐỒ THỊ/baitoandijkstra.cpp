#include <bits/stdc++.h>

using namespace std;
typedef pair<int, string> p;

void dijkstra(map<string, vector<pair<string, int>>> &g, string start, string end)
{
    map<string, int> dis;
    map<string, string> prev;
    priority_queue<p, vector<p>, greater<p>> pq;
    for (auto &it : g)
    {
        dis[it.first] = INT_MAX;
    }
    dis[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto [curdis, u] = pq.top();
        pq.pop();
        if (u == end)
            break;
        for (auto &[v, weight] : g[u])
        {
            int newdis = curdis + weight;
            if (newdis < dis[v])
            {
                dis[v] = newdis;
                prev[v] = u;
                pq.push({newdis, v});
            }
        }
    }
    if (dis[end] == INT_MAX)
    {
        cout << "Khong co duong di tu" << start << " den " << endl;
        return;
    }
    cout << "Duong di ngan nhat: " << dis[end] << endl;
    cout << "Duong di: ";
    stack<string> path;
    for (string at = end; at != ""; at = prev[at])
    {
        path.push(at);
        if (at == start)
            break;
    }
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    map<string, vector<pair<string, int>>> g;
    for (int i = 0; i < n; i++)
    {
        string u, v;
        int w;
        cin >> u >> v;
        cin >> w;
        g[u].push_back({v, w});
    }
    string s, f;
    cin >> s >> f;
    dijkstra(g, s, f);
}