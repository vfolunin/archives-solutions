#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(1e6 + 1);
    res[0] = res[1] = res[2] = res[3] = 1;

    double fSize = log10(6);
    for (int i = 4; i < res.size(); i++) {
        fSize += log10(i);
        res[i] = fSize + 1;
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