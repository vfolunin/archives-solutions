#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(100001);
    res[1] = 1;
    for (int i = 2; i < res.size(); i++) {
        res[i] = 1e9;
        for (int j = 1, f = 1; f <= i; j++, f *= j)
            res[i] = min(res[i], 1 + res[i - f]);
    }
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<int> res = prepare();

    cout << res[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}