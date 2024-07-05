#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void dfs(map<char, set<char>> &graph, char v, set<char> &visited, string &order) {
    visited.insert(v);
    for (char to : graph[v])
        if (!visited.count(to))
            dfs(graph, to, visited, order);
    order += v;
}

bool solve() {
    map<char, set<char>> graph;

    string a, b;
    set<char> chars;
    while (1) {
        a = b;
        if (!(cin >> b))
            return 0;
        if (b == "#")
            break;

        chars.insert(b.begin(), b.end());
        if (a.empty())
            continue;

        int i = 0;
        while (i < a.size() && a[i] == b[i])
            i++;

        if (i < a.size())
            graph[a[i]].insert(b[i]);
    }

    set<char> visited;
    string order;
    for (char c : chars)
        if (!visited.count(c))
            dfs(graph, c, visited, order);
    reverse(order.begin(), order.end());

    cout << order << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}