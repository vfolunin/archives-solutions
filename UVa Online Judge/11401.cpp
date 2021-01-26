#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> precalc() {
    vector<long long> res = { 0 };
    for (long long i = 1; i <= 1e6; i++)
        res.push_back(res.back() + i * i / 4);
    return res;
}

bool solve() {
    int n;
    cin >> n;

    if (n < 3)
        return 0;

    static vector<long long> res = precalc();
    cout << res[n - 2] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}