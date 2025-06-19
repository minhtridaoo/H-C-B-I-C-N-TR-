#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main()
{
    int n, m, source;
    cin >> n >> m >> source;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Cạnh từ u đến v với trọng số w
        // Nếu là đồ thị vô hướng, thêm cả adj[v].push_back({u, w});
    }

    vector<int> dist(n, INF);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
        {
            continue; // Đã tìm thấy đường đi ngắn hơn trước đó
        }

        for (const auto &edge : adj[u])
        {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // In khoảng cách ngắn nhất từ đỉnh nguồn đến các đỉnh khác
    for (int i = 0; i < n; ++i)
    {
        cout << "Khoảng cách từ " << source << " đến " << i << " là: ";
        if (dist[i] == INF)
        {
            cout << "Vô cùng" << endl;
        }
        else
        {
            cout << dist[i] << endl;
        }
    }

    return 0;
}
