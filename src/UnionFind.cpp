/*
    Daniel Rodriguez-Florido 7-17
    UFDS
*/

#include <bits/stdc++.h>

using namespace std;

int parent[1000000];
int ranks[1000000];

int search(int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = search(parent[v]);
}

void unite(int a, int b) {
    a = search(a);
    b = search(b);

    if (a == b)
        return;

    if (ranks[a] < ranks[b])
        parent[a] = b;
    else {
        parent[b] = a;
        if (ranks[a] == ranks[b])
            ranks[a]++;
    }
}

int main() {

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    for (int i = 0; i < N; i++)
        parent[i] = i;

    for (int i = 0; i < Q; i++) {
        string query;
        cin >> query;

        int a, b;
        cin >> a >> b;

        if (query == "=")
           unite(a,b);
        else
            if (search(a) == search(b))
                cout << "yes\n";
            else
                cout << "no\n";
    }

}
