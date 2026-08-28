#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool can(vector<pair<int, int>> &pairs, int threshold, long long time) {
    long long sum = 0;
    for (auto &[a, b] : pairs)
        sum += max(0LL, a * time - b);
    return sum >= threshold;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int pairCount, threshold;
    cin >> pairCount >> threshold;

    vector<pair<int, int>> pairs(pairCount);
    for (auto &[a, b] : pairs)
        cin >> a >> b;

    long long l = 0, r = 1;
    while (!can(pairs, threshold, r))
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (can(pairs, threshold, m))
            r = m;
        else
            l = m;
    }

    cout << r;
}