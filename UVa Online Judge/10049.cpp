#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> to = { 0, 1, 3 };
    for (long long n = 3; to.back() < 2e9; n++) {
        int k = lower_bound(to.begin(), to.end(), n) - to.begin();
        to.push_back(to.back() + k);
    }
    return to;
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;

    static vector<long long> to = prepare();
    int res = lower_bound(to.begin(), to.end(), n) - to.begin();

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}