#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> ops(n + 1, 1e9), from(n + 1);

    ops[1] = 0;

    for (int i = 2; i <= n; i++) {
        ops[i] = ops[i - 1] + 1;
        from[i] = i - 1;

        if (i % 2 == 0 && ops[i] > ops[i / 2] + 1) {
            ops[i] = ops[i / 2] + 1;
            from[i] = i / 2;
        }

        if (i % 3 == 0 && ops[i] > ops[i / 3] + 1) {
            ops[i] = ops[i / 3] + 1;
            from[i] = i / 3;
        }
    }

    vector<int> path;
    for (int v = n; v; v = from[v])
        path.push_back(v);
    reverse(path.begin(), path.end());
    
    cout << path.size() - 1 << "\n";
    for (int v : path)
        cout << v << " ";
}