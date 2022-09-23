#include <bits/stdc++.h>

#define endl "\n"
#define eb emplace_back
#define ll long long

using namespace std;

void solve() {

    string bapc;
    cin >> bapc;

    int n;
    cin >> n;

    string arr;
    cin >> arr;

    if (n == 0) {
        if (bapc.find('D') != string::npos)
            cout << "error" << endl;
        else
            cout << "[]" << endl;
        return;
    }

    vector<int> nums;
    string currNum;
    for (int i = 1; i < arr.size()-1; i++) {
        if (arr[i] != ',')
            currNum += arr.substr(i, 1);
        else {
            nums.eb(stoi(currNum));
            currNum = "";
        }
    }
    nums.eb(stoi(currNum));

    bool rev = false; // 0 is normal, 1 is reversed

    int frontInd = 0, backInd = nums.size();
    for (int i = 0; i < bapc.size(); i++) {
        if (bapc[i] == 'R')
            rev = !rev;
        else if (frontInd >= backInd) {
            cout << "error" << endl;
            return;
        }
        else if (!rev)
            frontInd++;
        else
            backInd--;
    }

    vector<int> ans;
    for (int i = frontInd; i < backInd; i++) {
        ans.eb(nums[i]);
    }

    if (ans.empty())
        cout << "[]" << endl;
    else {
        if (rev == 1)
            reverse(ans.begin(), ans.end());
        cout << "[";
        for (int i = 0; i < ans.size() - 1; i++)
            cout << ans[i] << ",";
        cout << ans[ans.size() - 1] << "]" << endl;
    }

}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int TC;
    cin >> TC;

    while (TC--) {
        solve();
    }

    return 0;

}
