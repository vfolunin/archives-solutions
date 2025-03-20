#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> readInts() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> res;
    int x;
    while (ss >> x)
        res.push_back(x);
    return res;
}

int dfs(vector<string> &a, vector<vector<int>> &visited, int y, int x) {
    visited[y][x] = 1;
    int size = 1;

    static vector<int> dy = { -1, 0, 1, 0 };
    static vector<int> dx = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        int ty = y + dy[d], tx = x + dx[d];
        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() &&
            !visited[ty][tx] && a[ty][tx] == a[y][x])
            size += dfs(a, visited, ty, tx);
    }

    return size;
}

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;
    cin.ignore();

    vector<string> a(size, string(size, 'a'));

    for (int i = 1; i < size; i++) {
        vector<int> coords = readInts();
        for (int j = 0; j < coords.size(); j += 2)
            a[coords[j] - 1][coords[j + 1] - 1] = 'a' + i;
    }

    vector<vector<int>> visited(size, vector<int>(size));

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (!visited[y][x] && dfs(a, visited, y, x) != size) {
                cout << "wrong\n";
                return 1;
            }
        }
    }

    cout << "good\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}