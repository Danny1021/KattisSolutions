#include <iostream>
#include <vector>
#include <sstream>
#include <numeric>
#include <string>
#include <algorithm>
#include <cmath>
#include <regex>
#include <map>
#include <set>
#include <queue>
#include <fstream>
#include <unordered_map>

using namespace std;

#define endl "\n"
#define eb emplace_back
#define ll long long

int main() {

    string str;
    cin >> str;

    vector<string> p;
    string curr = "";
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ';') {
            p.emplace_back(curr);
            curr = "";
        }
        else
            curr += str[i];
    }
    p.emplace_back(curr);

    int ans = 0;
    for (auto n : p) {
        if (n.find('-') == string::npos)
            ans++;
        else
            ans += abs( stoi(n.substr(0, n.find('-'))) - stoi(n.substr(n.find('-') + 1))) + 1;
    }

    cout << ans << endl;

}
