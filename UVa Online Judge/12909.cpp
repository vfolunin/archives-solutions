#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> res = { 0, 1 };
    for (int i = 2; res.back() <= 1e15; i++)
        res.push_back(6 * res[i - 1] - res[i - 2] + 2);
    return res;
}

bool solve() {
    long long n;
    cin >> n;

    if (!n)
        return 0;
    
    static vector<long long> res = prepare();

    cout << upper_bound(res.begin(), res.end(), n) - res.begin() - 2 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}