#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool hasRepeatingDigits(int n) {
    vector<int> has(10);
    while (n) {
        if (has[n % 10])
            return 1;
        has[n % 10] = 1;
        n /= 10;
    }
    return 0;
}

vector<int> prepare() {
    vector<int> v;
    for (int i = 1; i <= 5000; i++)
        if (!hasRepeatingDigits(i))
            v.push_back(i);
    return v;
}

bool solve() {
    int l, r;
    if (!(cin >> l >> r))
        return 0;

    static vector<int> v = prepare();
    cout << upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}