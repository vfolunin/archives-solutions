#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> res(1e6 + 1);
    long long product = 1, mod = 1e12;
    for (int i = 1; i < res.size(); i++) {
        product *= i;
        while (product % 10 == 0)
            product /= 10;
        product %= mod;
        res[i] = product % 10;
    }
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
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