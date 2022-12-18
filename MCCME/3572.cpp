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

    vector<int> res(n + 1, 1e9);
    res[0] = 0;

    for (int i = 1; i <= n; i++) {
        res[i] = res[i - 1] + i % 10;
        if (i >= 2)
            res[i] = min(res[i], res[i - 2] + i % 10);
    }

    cout << res[n];
}