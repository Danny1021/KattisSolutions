#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int nums;
    cin >> nums;

    int arr [nums];
    for (int i = 0; i < nums; i++)
        cin >> arr[i];

    int count;
    count = 0;

    for (int i = 0; i < nums; i++) {
        if (arr[i] < 0)
            count++;
    }

    cout << count;

    return 0;
}
