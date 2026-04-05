#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ones(int n) {
    int res = 0;
    while (n) {
        res++;
        n &= n - 1;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<long long> count(1 << 10);
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        int mask = 0;
        for (char c : s)
            mask |= 1 << (c - '0');

        for (int submask = mask; submask; submask = (submask - 1) & mask)
            count[submask]++;
    }

    long long res = 0;
    for (int mask = 1; mask < count.size(); mask++)
        res += count[mask] * (count[mask] - 1) / 2 * (ones(mask) % 2 ? 1 : -1);

    cout << res;
}