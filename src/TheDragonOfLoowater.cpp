#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define eb emplace_back
#define ll long long

void solve(int n, int m) {

    vector<int> dragonHeads(n);
    vector<int> knights(m);

    for (int i = 0; i < n; i++)
        cin >> dragonHeads[i];
    for (int i = 0; i < m; i++)
        cin >> knights[i];

    sort(dragonHeads.begin(), dragonHeads.end());
    sort(knights.begin(), knights.end());

    int ans = 0;

    int i = 0, j = 0;
    while (j < knights.size() && i < dragonHeads.size()) {
        if (knights[j] < dragonHeads[i])
            j++;
        else if (knights[j] >= dragonHeads[i]) {
            ans += knights[j];
            i++; j++;
        }
    }

    if (i < dragonHeads.size()) {
        cout << "Loowater is doomed!" << endl;
    }
    else {
        cout << ans << endl;
    }

}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        solve(n, m);
    }

    return 0;
}
