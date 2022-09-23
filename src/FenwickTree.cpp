#include <bits/stdc++.h>

using namespace std;

long long fenwick[5000000];

void update(int size, int index, int value) {
    while (index < size) {
        fenwick[index] += value;
        index += (index)&(-index);
    }
}

long long sum(int index) {
    long long s = 0;
    while (index > 0) {
        s += fenwick[index];
        index -= (index)&(-index);
    }
    return s;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int size, operations;
    cin >> size >> operations;

    long long a, b;
    char operation;
    for (int i = 0; i < operations; i++) {
        cin >> operation;
        if (operation == '+') {
            cin >> a >> b;
            update(size+1, a+1, b);
        }
        if (operation == '?') {
            cin >> a;
            cout << sum(a) << "\n";
        }
    }

    return 0;
}
