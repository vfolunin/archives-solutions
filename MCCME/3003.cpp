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

    int n, k;
    cin >> n >> k;

    vector<vector<long long>> ways(n + 1, vector<long long>(k + 1));
    ways[0].assign(k + 1, 1);

    for (int sum = 1; sum <= n; sum++)
        for (int last = 1; last <= k; last++)
            ways[sum][last] = ways[sum][last - 1] + (sum >= last ? ways[sum - last][last] : 0);

    cout << ways[n][k];
}