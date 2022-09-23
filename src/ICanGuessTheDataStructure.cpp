#include <bits/stdc++.h>

//#define endl "\n"
#define eb emplace_back

using namespace std;

void solve(int n) {

    vector<int> v;
    queue<int> q;
    stack<int> s;
    priority_queue<int, vector<int>, less<int>> pq;

    int operations[3] = {0, 0, 0};

    for (int i = 0; i < n; i++) {
        int op, num;
        cin >> op >> num;
        if (op == 1) {
            v.eb(num);
            q.push(num);
            operations[0]++;
            s.push(num);
            operations[1]++;
            pq.push(num);
            operations[2]++;
        }
        if (op == 2) {
            if (find(v.begin(), v.end(), num) == v.end()) {
                cout << "impossible" << endl;
                for (int j = i+1; j < n; j++)
                    cin >> op >> num;
                return;
            }
            v.erase(find(v.begin(), v.end(), num));
            if (q.front() == num) {
                q.pop();
                operations[0]++;
            }
            if (s.top() == num) {
                s.pop();
                operations[1]++;
            }
            if (pq.top() == num) {
                pq.pop();
                operations[2]++;
            }
        }
    }

    if (operations[0] == n && operations[1] == n || operations[1] == n && operations[2] == n || operations[0] == n && operations[2] == n)
        cout << "not sure" << endl;
    else {
        if (operations[0] == n)
            cout << "queue" << endl;
        else if (operations[1] == n)
            cout << "stack" << endl;
        else if (operations[2] == n)
            cout << "priority queue" << endl;
        else
            cout << "impossible" << endl;
    }

}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    while (cin >> n)
        solve(n);

}
