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

    vector<int> ops(n + 1);
    for (int i = 2; i <= n; i++) {
        ops[i] = ops[i - 1] + 1;
        if (i % 2 == 0)
            ops[i] = min(ops[i], ops[i / 2] + 1);
        if (i % 3 == 0)
            ops[i] = min(ops[i], ops[i / 3] + 1);
    }

    cout << ops[n];
}