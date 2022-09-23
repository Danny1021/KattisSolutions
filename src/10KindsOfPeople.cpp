#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>

#define endl "\n";
#define eb emplace_back;

using namespace std;

int transR[4] = {0, 0, -1, 1};
int transC[4] = {1, -1, 0, 0};

bool inBounds(int R, int C, int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C;
}

int main() {

    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int r, c;
    cin >> r >> c;

    string grid[r];
    for (int i = 0; i < r; i++)
        cin >> grid[i];

    int islands[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            islands[i][j] = -1;
        }
    }

    int islandNum = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(0,0));

    int k = 0, l = 0;

    while (!q.empty()) {

        pair<int, int> curr = q.front();
        q.pop();
        islands[curr.first][curr.second] = islandNum;

        for (int i = 0; i < 4; i++) {
            int newR = curr.first + transR[i];
            int newC = curr.second + transC[i];
            if (inBounds(r, c, newR, newC) && grid[newR][newC] == grid[curr.first][curr.second] && islands[newR][newC] == -1) {
                q.push(make_pair(newR, newC));
                islands[newR][newC] = islandNum;
            }
        }

        nextIter:
        if (q.empty()) {
            for (; k < r; k++) {
                for (l = 0; l < c; l++) {
                    if (islands[k][l] == -1) {
                        q.push(make_pair(k, l));
                        islandNum++;
                        goto nextIter;
                    }
                }
            }
        }

    }

    int n;
    cin >> n;
    while (n-- > 0) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--; r2--; c2--;

        if (islands[r1][c1] == islands[r2][c2]) {
            if (grid[r1][c1] == '0') {
                cout << "binary" << endl;
            }
            else
                cout << "decimal" << endl;
        }
        else
            cout << "neither" << endl;
    }

    return 0;
}
