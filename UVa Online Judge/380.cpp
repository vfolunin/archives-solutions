#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string dfs(map<string, map<pair<int, int>, string>> graph, string &v, int time, set<string> &visited) {
    visited.insert(v);
    
    auto it = graph[v].lower_bound({ time, 1e9 });
    if (it == graph[v].begin())
        return v;

    it--;
    if (time < it->first.first || it->first.second < time)
        return v;

    if (visited.count(it->second))
        return "9999";

    return dfs(graph, it->second, time, visited);
}

void solve(int test) {
    map<string, map<pair<int, int>, string>> graph;

    while (1) {
        string from;
        cin >> from;

        if (from == "0000")
            break;

        int start, duration;
        string to;
        cin >> start >> duration >> to;

        graph[from][{start, start + duration}] = to;
    }

    cout << "SYSTEM " << test << "\n";
    while (1) {
        int time;
        cin >> time;

        if (time == 9000)
            break;

        string from;
        cin >> from;

        set<string> visited;
        string to = dfs(graph, from, time, visited);

        cout << "AT " << setw(4) << setfill('0') << time << " CALL TO " << from << " RINGS " << to << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << "CALL FORWARDING OUTPUT\n";
    for (int test = 1; test <= n; test++)
        solve(test);
    cout << "END OF OUTPUT\n";
}