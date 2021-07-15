#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool rec(string &s, int i, vector<string> &a, int y, int x, vector<vector<int>> &visited) {
    if (i == s.size())
        return 1;

    if (visited[y][x] || a[y][x] != s[i])
        return 0;

    visited[y][x] = 1;

    int dy[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    
    for (int d = 0; d < 8; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < 4 && 0 <= tx && tx < 4 && rec(s, i + 1, a, ty, tx, visited))
            return 1;
    }

    visited[y][x] = 0;

    return 0;
}

int score(vector<string> &a, string &s) {
    vector<vector<int>> visited(4, vector<int>(4));
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (rec(s, 0, a, y, x, visited)) {
                static int points[] = { 0, 0, 0, 1, 1, 2, 3, 5 };
                return s.size() > 7 ? 11 : points[s.size()];
            }
        }
    }
    return 0;
}

void solve(int test) {
    vector<string> a(4);
    for (string &row : a)
        cin >> row;

    int wordCount;
    cin >> wordCount;

    int res = 0;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        res += score(a, word);
    }

    cout << "Score for Boggle game #" << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}