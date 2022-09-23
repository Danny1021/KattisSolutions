#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define eb emplace_back
#define ll long long

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n;

    unordered_map<string, vector<int>> cunt;
    for (int i = 0; i < n; i++) {
        string s; int r;
        cin >> s >> r;
        if (cunt.find(s) != cunt.end()) {
            cunt[s].eb(r);
        }
        else {
            vector<int> temp;
            cunt.insert(make_pair(s, temp));
            cunt[s].eb(0);
            cunt[s].eb(r);
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string s; int r;
        cin >> s >> r;
        if (cunt[s][0] == 0 && cunt[s].size() > 1) {
            sort(cunt[s].begin(), cunt[s].end());
            cunt[s][0] = 1;
        }
        cout << cunt[s][r] << endl;
    }

    return 0;
}
