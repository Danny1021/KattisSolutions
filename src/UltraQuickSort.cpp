#include <bits/stdc++.h>

using namespace std;

pair <vector<int> , long> mergeSortInversions(vector<int> vec) {
    if (vec.size() == 1)
        return make_pair(vec, 0);

    vector<int> a;
    vector<int> b;
    vector<int> merged;

    for (int i = 0; i < vec.size()/2; i++)
        a.push_back(vec[i]);
    for (int i = vec.size()/2; i < vec.size(); i++)
        b.push_back(vec[i]);
    pair<vector<int>, long> a1 = mergeSortInversions(a);
    pair<vector<int>, long> b1 = mergeSortInversions(b);
    long inversions = a1.second + b1.second;

    int i = 0, j = 0;

    while (i < a1.first.size() && j < b1.first.size()) {
        if (a1.first[i] <= b1.first[j]) {
            merged.push_back(a1.first[i]);
            i++;
        }
        else {
            merged.push_back(b1.first[j]);
            j++;
            inversions += (a1.first.size() - i);
        }
    }

    if (i != a1.first.size()) {
        for (int k = i; k < a1.first.size(); k++)
            merged.push_back(a1.first[k]);
    }
    if (j != b1.first.size()) {
        for (int k = j; k < b1.first.size(); k++)
            merged.push_back(b1.first[k]);
    }

    return make_pair(merged, inversions);
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    pair<vector<int>, long> pair1 = mergeSortInversions((nums));

    cout << pair1.second << endl;

    return 0;
}
