#include <bits/stdc++.h>

using namespace std;

int main() {

    int jackCT, jillCT;

    while (cin >> jackCT >> jillCT && jackCT != 0 && jillCT != 0) {

        vector<int> jackCD, jillCD, unique;

        int temp;
        for (int i = 0; i < jackCT; i++) {
            cin >> temp;
            jackCD.push_back(temp);
        }

        for (int i = 0; i < jillCT; i++) {
            cin >> temp;
            jillCD.push_back(temp);
        }

        set_intersection(jackCD.begin(), jackCD.end(), jillCD.begin(), jillCD.end(), back_inserter(unique));

        cout << unique.size() << endl;
    }

    return 0;
}
