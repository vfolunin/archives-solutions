#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

bool solve() {
    int size, summandCount;
    if (!(cin >> size >> summandCount))
        return 0;

    vector<int> a(size);
    for (int &x : a)
        cin >> x;

    sort(a.rbegin(), a.rend());
    long long sum = 0;

    for (int i = 0; i < summandCount; i++)
        sum = (sum + a[i]) % MOD;

    cout << sum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}