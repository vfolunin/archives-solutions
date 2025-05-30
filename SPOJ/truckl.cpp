#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

long long rec(long long size, long long limit, unordered_map<long long, long long> &memo) {
    long long &res = memo[size];
    if (res)
        return res;

    if (size <= limit)
        return res = 1;

    return res = rec(size / 2, limit, memo) + rec((size + 1) / 2, limit, memo);
}

bool solve() {
    long long size, limit;
    if (!(cin >> size >> limit))
        return 0;

    if (limit == 1) {
        cout << size << "\n";
        return 1;
    }

    unordered_map<long long, long long> memo;
    cout << rec(size, limit, memo) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}