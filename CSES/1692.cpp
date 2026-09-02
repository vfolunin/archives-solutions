#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string deBruijn(int size) {
    if (size == 1)
        return "01";
    size--;

    vector<multiset<int>> graph(1 << size);
    for (int v = 0; v < graph.size(); v++) {
        int lastBits = v & ((1 << (size - 1)) - 1);
        graph[v].insert(lastBits * 2);
        graph[v].insert(lastBits * 2 + 1);
    }

    vector<int> stack = { 0 }, cycle;
    while (!stack.empty()) {
        int v = stack.back();
        if (!graph[v].empty()) {
            int to = *graph[v].begin();
            graph[v].erase(graph[v].find(to));
            stack.push_back(to);
        } else {
            stack.pop_back();
            cycle.push_back(v);
        }
    }
    reverse(cycle.begin(), cycle.end());

    string res(size, '0');
    for (int i = 1; i < cycle.size(); i++)
        res += cycle[i] % 2 + '0';
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    cout << deBruijn(size);
}