#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define eb emplace_back
#define ll long long
#define pill pair<int, long long>

ll oo = 1e14;
ll dist[10000];

class Compare {
public:
    bool operator() (pill a, pill b) {
        return a.second > b.second;
    }
};

void dijkstra(int src, vector<vector<pill>>& graph) {
    dist[src] = 0;
    priority_queue<pill, vector<pill>, Compare> pq;
    pq.push(make_pair(src,0));

    while (!pq.empty()) {
        pill curr = pq.top();
        pq.pop();

        if (dist[curr.first] != curr.second)
            continue;

        for (auto it = graph[curr.first].begin(); it != graph[curr.first].end(); it++) {
            int v = it->first;
            int w = it->second;
            if (dist[v] > dist[curr.first] + w) {
                dist[v] = dist[curr.first] + w;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }

}

int main() {

    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m, q, src;
    while (cin >> n >> m >> q >> src) {
        if (n == 0 && m == 0 && q == 0 && src == 0) break;

        fill(dist, dist + n, oo);

        vector<vector<pill>> graph(n + 1);
        for (int i = 0; i < m; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            graph[a].eb(make_pair(b, c));
        }

        dijkstra(src, graph);
        while (q-- > 0) {
            int v;
            cin >> v;
            dist[v] == oo ? cout << "Impossible" << endl : cout << dist[v] << endl;
        }

        cout << endl;

    }

    return 0;

}
