#include <bits/stdc++.h>

using namespace std;

int main() {

    int size;
    cin >> size;

    int nums[size];
    multiset<long> right;
    int maxLeft, minRight = 2147483647;
    for(int i = 0; i < size; i++) {
        int n;
        cin >> n;
        nums[i] = n;
        if (i > 0)
            right.insert(n);
        if (nums[i] < minRight)
            minRight = nums[i];
    }

    maxLeft = nums[0];
    int pivots = 0;

    for (int i = 0; i < size; i++) {
        if (nums[i-1] > maxLeft)
            maxLeft = nums[i-1];
        right.erase(nums[i]);
        if (nums[i] <= minRight || nums[i-1] <= minRight)
            minRight = *right.begin();
        if (maxLeft <= nums[i] && (minRight > nums[i] || right.empty()))
            pivots++;
    }

    cout << pivots;

    return 0;
}
