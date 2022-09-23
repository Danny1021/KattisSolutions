#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main() {
    int N, t;
    cin >> N >> t;
    int arry[N];
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arry[i] = a;
    }
    int arr[3];
    ll sum = 0;
    ll even_sum = 0;
    vector<int> visited;
    string sequence = "";

    for (int i = 0; i < N; i++) {
        sequence += alpha[arry[i] % 26];
        sum += arry[i];
        if (arry[i] % 2 == 0)
            even_sum += arry[i];
    }
    for (int i = 0; i < 3; i++) {
        arr[i] = arry[i];
    }
    sort(arr, arr + 3);
    if (t == 1) {
        cout << "7";
        return 0;
    }
    else if (t == 2) {
        if (arry[0] > arry[1]) {
            cout << "Bigger";
            return 0;
        } else if (arry[0] == arry[1]) {
            cout << "Equal";
            return 0;
        } else {
            cout << "Smaller";
            return 0;
        }
    }
    else if (t == 3) {
        cout << arr[1];
        return 0;
    }
    else if (t == 4) {
        cout << sum;
        return 0;
    }
    else if (t == 5) {
        cout << even_sum;
        return 0;
    }
    else if (t == 6) {
        cout << sequence;
        return 0;
    }
    else {
        int index = 0;
        for (int i = 0; i < N; i++) {
            index = arry[index];
            if (index > N-1) {
                cout << "Out";
                return 0;
            } else if (index == N-1) {
                cout << "Done";
                return 0;
            }
        }
        cout << "Cyclic";
        return 0;
    }

}
