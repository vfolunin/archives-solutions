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

    vector<int> res(n + 1);
    for (int i = 2; i <= n; i++) {
        res[i] = res[i - 1] + 1;
        if (i % 2 == 0)
            res[i] = min(res[i], res[i / 2] + 1);
        if (i % 5 == 0)
            res[i] = min(res[i], res[i / 5] + 1);
    }

    cout << res[n];
}