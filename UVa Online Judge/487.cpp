#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<string> &a, int y, int x, vector<vector<int>> &visited, vector<vector<set<string>>> &words) {
    visited[y][x] = 1;
    words[y][x] = { string(1, a[y][x]) };

    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (!dy && !dx)
                continue;

            int ty = y + dy, tx = x + dx;
            if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && a[y][x] < a[ty][tx]) {
                if (!visited[ty][tx])
                    dfs(a, ty, tx, visited, words);
                for (string word : words[ty][tx])
                    words[y][x].insert(a[y][x] + word);
            }
        }
    }
}

bool compare(string &a, string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

void solve(int test) {
    int size;
    cin >> size;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> visited(size, vector<int>(size));
    vector<vector<set<string>>> words(size, vector<set<string>>(size));

    set<string> resSet;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (!visited[y][x])
                dfs(a, y, x, visited, words);
            resSet.insert(words[y][x].begin(), words[y][x].end());
        }
    }

    vector<string> res(resSet.begin(), resSet.end());
    sort(res.begin(), res.end(), compare);

    if (test)
        cout << "\n";
    for (string &word : res)
        if (word.size() >= 3)
            cout << word << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}