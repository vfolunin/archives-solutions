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
    res[1] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j + j <= i; j++)
            res[i] = min(res[i], res[j] + res[i - j]);
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0)
                res[i] = min(res[i], res[j] + res[i / j]);
    }

    cout << res[n];
}