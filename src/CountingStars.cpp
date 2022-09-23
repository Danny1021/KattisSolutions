#include <bits/stdc++.h>

using namespace std;

#define pb push_back

string grid[101];
int islands[101][101];
int islandNum, rows, cols;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool inBounds(int r, int c, int R, int C) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

void bfs(pair<int, int> start) {

    queue<pair<int, int>> q;

    q.push(start);
    islands[start.first][start.second] = islandNum;

    while (!q.empty()) {

        pair<int, int> curr = q.front();
        q.pop();
        int newR, newC;
        for (int i = 0; i < 4; i++) {
            newR = curr.first + dx[i], newC = curr.second + dy[i];
            if (!inBounds(newR, newC, rows, cols) || islands[newR][newC] != -1 || grid[newR][newC] != '-')
                continue;
            islands[newR][newC] = islandNum;
            q.push(make_pair(newR, newC));
        }
    }

    islandNum++;
}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int Case = 1;

    while(cin >> rows >> cols) {

        islandNum = 1;

        for(int i = 0; i < rows; i++) {
            cin >> grid[i];
            for (int j = 0; j < cols; j++) {
                islands[i][j] = -1;
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (inBounds(i, j, rows, cols) && grid[i][j] == '-' && islands[i][j] == -1)
                    bfs(make_pair(i,j));
            }
        }

        printf("Case %d: %d\n", Case, islandNum-1);
        Case++;
    }

    return 0;

}
