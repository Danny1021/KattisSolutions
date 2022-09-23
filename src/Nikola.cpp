#include <bits/stdc++.h>

//#define endl "\n"
#define eb emplace_back
#define ll long long

using namespace std;

ll oo = 1e9;
int n;
int fees[1005];
ll dp[1005][1005];

ll memoization(int ind, int lastStep) {

    if (ind == n-1)
        return fees[n-1];
    if (ind > n-1)
        return oo;
    if (ind < 0)
        return oo;

    if (dp[ind][lastStep] != oo)
        return dp[ind][lastStep];

    if (ind == 0 && lastStep == 0)
        return dp[ind][0] = memoization(ind+lastStep+1, 1);
    return dp[ind][lastStep] = min(fees[ind] + memoization(ind+lastStep+1, lastStep+1), fees[ind] + memoization(ind-lastStep, lastStep));

}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = oo;
        }
    }

    for (int i = 0; i < n; i++)
        cin >> fees[i];

    cout << memoization(0, 0) << endl;

    return 0;

}
