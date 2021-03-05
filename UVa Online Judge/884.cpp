#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(1e6 + 1);
    res[2] = 1;
    for (int i = 3; i < res.size(); i++) {
        long long d = 2;
        while (d * d <= i && i % d)
            d++;
        if (d * d > i)
            d = i;
        res[i] = res[i / d] + 1;
    }
    for (int i = 3; i < res.size(); i++)
        res[i] += res[i - 1];
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

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (solve());
}