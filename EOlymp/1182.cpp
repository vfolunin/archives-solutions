#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool solve() {
    vector<int> a;
    for (int value; cin >> value && value; )
        a.push_back(value);

    if (a.empty())
        return 0;

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = 0; i + 1 < a.size(); i++)
        res = gcd(res, a[i + 1] - a[i]);

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}