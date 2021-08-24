#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long n;
    if (!(cin >> n))
        return 0;

    int swappedCount;
    cin >> swappedCount;

    vector<int> swapped(swappedCount);
    string mask;
    for (int &s : swapped) {
        cin >> s;
        mask += (bool)(n & (1LL << s));
        n &= ~(1LL << s);
    }

    long long res = 0;

    sort(mask.begin(), mask.end());
    do {
        long long cur = n;
        for (int i = 0; i < swappedCount; i++)
            cur |= (long long)mask[i] << swapped[i];

        if (cur % 7 == 0)
            res = max(res, cur);
    } while (next_permutation(mask.begin(), mask.end()));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}