#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long factorial(int n) {
    static vector<long long> memo(13);
    long long &res = memo[n];
    if (res)
        return res;

    if (n <= 1)
        return res = 1;

    return res = factorial(n - 1) * n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> count(26);
    int totalCount = 0;

    for (char c; cin >> c; ) {
        count[c - 'a']++;
        totalCount++;
    }

    long long res = factorial(totalCount);
    for (int count : count)
        res /= factorial(count);

    cout << res;
}