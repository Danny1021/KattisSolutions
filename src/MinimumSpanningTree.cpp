#include <bits/stdc++.h>

using namespace std;

//#define endl "\n"
#define eb emplace_back

struct edge {
    int a, b, w;

    edge(int a, int b, int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int parent[20001];
int ranks[20001];

int find_set(int n) {
    if (n == parent[n])
        return n;
    return parent[n] = find_set(parent[n]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ranks[a] < ranks[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}

void solve() {

    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0)
        exit(0);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            edges.emplace_back(b,a,c);
        else
            edges.emplace_back(a,b,c);
    }

    sort(edges.begin(), edges.end(), [] (edge a, edge b) {
        return a.w > b.w;
    });

    long long conn = 0, cost = 0;
    vector<edge> used;

    while (!edges.empty()) {
        if (conn == n-1)
            break;
        int a = (edges.end()-1)->a, b = (edges.end()-1)->b;
        if (find_set(a) != find_set(b)) {
            union_sets(a,b);
            used.push_back(edges[edges.size()-1]);
            conn++;
            cost += (edges.end()-1)->w;
        }
        edges.erase(edges.end()-1);
    }

    sort(used.begin(), used.end(), [] (edge a, edge b) {
        if (a.a == b.a)
            return a.b < b.b;
        return a.a < b.a;
    });

    if (conn == n-1) {
        cout << cost << endl;
        for (auto i : used) {
            cout << i.a << " " << i.b << endl;
        }
    }
    else
        cout << "Impossible" << endl;

}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    while(true) {
        solve();
    }

    return 0;

}
