#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define eb emplace_back
#define ll long long

string alpha = "abcdefghijklmnopqrstuvwxyz";

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string str;
    cin >> str;

    int n;
    cin >> n;

    vector<vector<string>> vec(26);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vec[alpha.find(s[0])].push_back(s);
    }

    int start = alpha.find(str[str.size()-1]);

    if (vec[start].empty())
        cout << "?" << endl;
    else {
        for (auto i : vec[start]) {
            if (vec[alpha.find(i[i.size()-1])].empty() ||
            (i[0] == i[i.size()-1] && vec[start].size() == 1)) {
                cout << i << "!" << endl;
                return 0;
            }
        }
        cout << vec[start][0] << endl;
    }

    return 0;
}
