#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, order);
    order.push_back(v);
}

void solve(int test) {
    vector<vector<int>> graph(26);
    vector<int> value(26);

    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;

        stringstream ss(line);
        char v;
        string from;
        ss >> v >> value[v - 'A'] >> from;
        
        for (char f : from)
            graph[f - 'A'].push_back(v - 'A');
    }

    vector<int> visited(26), order;
    for (int v = 0; v < 26; v++)
        if (!visited[v])
            dfs(graph, v, visited, order);
    reverse(order.begin(), order.end());

    vector<int> pathValue(26);
    for (int v : order) {
        pathValue[v] += value[v];
        for (int to : graph[v])
            pathValue[to] = max(pathValue[to], pathValue[v]);
    }

    if (test)
        cout << "\n";
    cout << *max_element(pathValue.begin(), pathValue.end()) << "\n";
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