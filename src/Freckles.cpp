#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int parent[1001];
int ranks[1001];

int find_set(int n) {
    if (n == parent[n])
        return n;
    return find_set(parent[n]);
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

struct Edge {
    int a, b;
    double w;

    Edge(int a, int b, double w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }

    bool operator<(Edge other) const {
        return w > other.w;
    }

};

double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt( pow(b.first-a.first, 2) + pow(b.second-a.second, 2));
}

void solve() {

    int n;
    cin >> n;

    unordered_map<int, pair<double, double>> m;

    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        m.insert(make_pair(i, make_pair(a, b)));
        parent[i] = i;
    }

    priority_queue<Edge> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            edges.push(Edge(i, j, dist(m[i], m[j])));
        }
    }

    int edgesAdded = 0;
    double totDist = 0;
    while (edgesAdded != n-1) {
        Edge curr = edges.top(); edges.pop();
        if (find_set(curr.a) != find_set(curr.b)) {
            union_sets(curr.a, curr.b);
            totDist += curr.w;
            edgesAdded++;
        }
    }

    printf("%.2f\n\n", totDist);

}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--) {
        solve();
    }

    return 0;
}
