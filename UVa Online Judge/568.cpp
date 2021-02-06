#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> res = { 1, 1 };
    for (int i = 2; i <= 10000; i++) {
        res.push_back(res.back() * i);
        while (res.back() % 10 == 0)
            res.back() /= 10;
        res.back() %= 1000000;
    }
    return res;
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static vector<long long> res = prepare();
    cout << setw(5) << n << " -> " << res[n] % 10 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}