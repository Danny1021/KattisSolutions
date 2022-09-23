#include <bits/stdc++.h>

using namespace std;

int main() {

    int days = 0;
    int printers = 1;
    int statues;
    cin >> statues;
    int currStatues = 0;

    while (printers < statues/2) {
        printers *= 2;
        days++;
    }

    while (currStatues < statues) {
        currStatues += printers;
        days++;
    }

    cout << days;

    return 0;
}
