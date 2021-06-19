#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> euler(vector<set<int>> &graph) {
    vector<int> stack = { 0 }, cycle;
    while (!stack.empty()) {
        int v = stack.back();
        if (!graph[v].empty()) {
            int to = *graph[v].begin();
            graph[v].erase(graph[v].begin());
            stack.push_back(to);
        } else {
            stack.pop_back();
            cycle.push_back(v);
        }
    }
    cycle.pop_back();
    reverse(cycle.begin(), cycle.end());
    return cycle;
}

bool solve() {
    int size, digitCount;
    if (!(cin >> size >> digitCount))
        return 0;

    if (size == 1) {
        for (int i = 0; i < digitCount; i++)
            cout << i;
        cout << "\n";
        return 1;
    }

    map<string, int> id;
    vector<string> val;

    string s(size - 1, '0');
    while (1) {
        id[s] = id.size();
        val.push_back(s);

        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0' + digitCount - 1)
            i--;
        
        if (i < 0)
            break;

        s[i]++;
        fill(s.begin() + i + 1, s.end(), '0');
    }

    vector<set<int>> graph(id.size());

    s.assign(size, '0');
    while (1) {
        graph[id[s.substr(0, size - 1)]].insert(id[s.substr(1)]);

        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0' + digitCount - 1)
            i--;

        if (i < 0)
            break;

        s[i]++;
        fill(s.begin() + i + 1, s.end(), '0');
    }

    vector<int> cycle = euler(graph);
    
    cout << string(size, '0');
    for (int i = 1; i + size <= cycle.size(); i++)
        cout << val[cycle[i]].back();
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}