#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    vector<int> a;
    while (1) {
        int value;
        cin >> value;

        a.push_back(value);

        if (!value)
            break;
    }

    vector<int> visited(a.size());
    queue<int> q;

    visited[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : { v - a[v], v + a[v] }) {
            if (0 <= to && to < a.size() && !visited[to]) {
                visited[to] = 1;
                q.push(to);
            }
        }
    }

    cout << "Puzzle " << test << " is " << (visited.back() ? "" : "not ") << "solvable.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++)
        solve(test);
}