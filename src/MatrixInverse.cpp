#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int i = 1;
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        int scale = a*d - b*c;
        cout << "Case " << i << ":" << endl;
        cout << scale*d << " " << -(scale*b) << endl << -(scale*c) << " " << scale*a << endl;
        i++;
    }

}
