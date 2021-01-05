#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited);
}

void solve(int test) {
    string s;
    getline(cin, s);

    int n = s[0] - 'A' + 1;
    vector<vector<int>> graph(n);

    while (1) {
        getline(cin, s);
        if (s.empty())
            break;
        graph[s[0] - 'A'].push_back(s[1] - 'A');
        graph[s[1] - 'A'].push_back(s[0] - 'A');
    }
    
    int res = 0;
    vector<int> visited(n);
    for (int v = 0; v < n; v++) {
        if (!visited[v]) {
            res++;
            dfs(graph, v, visited);
        }
    }

    if (test)
        cout << "\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore(2);

    for (int i = 0; i < n; i++)
        solve(i);
}