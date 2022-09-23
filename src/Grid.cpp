#include <bits/stdc++.h>

using namespace std;

//#define endl "\n"
#define eb emplace_back

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool inBounds(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void solve() {

    int r, c;
    cin >> r >> c;

    string grid[r];
    for (int i = 0; i < r; i++)
        cin >> grid[i];

    int dist[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            dist[i][j] = -1;
        }
    }

    queue<pair<int,int>> q;
    dist[0][0] = 0;

    q.push(make_pair(0,0));
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newR = curr.first + (grid[curr.first][curr.second]-48)*dx[i], newC = curr.second + (grid[curr.first][curr.second]-48)*dy[i];
            if (!inBounds(newR, newC, r, c) || dist[newR][newC] != -1)
                continue;
            dist[newR][newC] = dist[curr.first][curr.second] + 1;
            q.push(make_pair(newR, newC));
        }
    }

    cout << dist[r-1][c-1] << endl;

}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();

    return 0;

}
