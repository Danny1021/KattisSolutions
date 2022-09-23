#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

long long evalDist(vector<pair<int, int>>& vec, pair<int, int> start) {
    long long ans = abs(vec[0].first - start.first) + abs(vec[0].second - start.second);
    for (int i = 0; i < vec.size()-1; i++) {
        ans += abs(vec[i].first - vec[i+1].first) + abs(vec[i].second - vec[i+1].second);
    }
    return ans + abs((end(vec)-1)->first - start.first) + abs((end(vec)-1)->second - start.second);
}

void solve() {

    int r, c, ri, ci;
    cin >> r >> c >> ri >> ci;

    int beepCt;
    cin >> beepCt;

    vector<pair<int, int>> beepers(beepCt);
    for (int i = 0; i < beepCt; i++) {
        int a, b;
         cin >> a >> b;
         beepers[i] = make_pair(a,b);
    }

    sort(begin(beepers), end(beepers));

    long long ans = 1e18;

    do {
        ans = min(ans, evalDist(beepers, make_pair(ri, ci)));
    } while (next_permutation(begin(beepers), end(beepers)));

    cout << ans << endl;

}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    while (n--)
        solve();

    return 0;
}
