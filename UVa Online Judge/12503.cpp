#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int x = 0;
    vector<int> ops(n);
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;

        if (op == "LEFT") {
            ops[i] = -1;
        } else if (op == "RIGHT") {
            ops[i] = 1;
        } else {
            int index;
            cin >> op >> index;
            ops[i] = ops[index - 1];
        }

        x += ops[i];
    }

    cout << x << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}