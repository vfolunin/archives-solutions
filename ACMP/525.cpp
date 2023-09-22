#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<vector<int>> ways(n + 1, vector<int>(10));
    ways[0][0] = 1;

    for (int sum = 1; sum <= n; sum++)
        for (int last = 0; (1 << last) <= sum; last++)
            for (int prev = 0; prev <= last; prev++)
                ways[sum][last] += ways[sum - (1 << last)][prev];

    int res = 0;
    for (int last = 0; (1 << last) <= n; last++)
        res += ways[n][last];

    cout << res;
}