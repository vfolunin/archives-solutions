#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<string> &a, int i, int j, vector<vector<int>> &visited, int color) {
    visited[i][j] = color;

    static int di[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
    static int dj[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
    
    for (int d = 0; d < 8; d++) {
        int ti = i + di[d];
        int tj = j + dj[d];
        if (0 <= ti && ti < a.size() && 0 <= tj && tj < a[0].size() && a[i][j] == a[ti][tj] && !visited[ti][tj])
            dfs(a, ti, tj, visited, color);
    }
}

bool solve() {
    vector<string> a;
    while (1) {
        string line;
        if (!(getline(cin, line)) || line == "%")
            break;
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        a.push_back(line);
    }

    if (a.empty())
        return 0;

    vector<vector<int>> visited(a.size(), vector<int>(a[0].size()));
    int color = 1;

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[0].size(); j++)
            if (!visited[i][j])
                dfs(a, i, j, visited, color++);

    vector<int> width(a[0].size());
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[0].size(); j++)
            width[j] = max<int>(width[j], to_string(visited[i][j]).size());

    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[0].size(); j++)
            cout << setw(width[j]) << visited[i][j] << (j + 1 < a[0].size() ? ' ' : '\n');
    cout << "%\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}