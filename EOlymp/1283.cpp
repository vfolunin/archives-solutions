#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> ways(1e4);
    ways[0] = 1;

    for (int coin : { 1, 5, 10, 25, 50 })
        for (int sum = coin; sum < ways.size(); sum++)
            ways[sum] += ways[sum - coin];

    return ways;
}

bool solve() {
    int sum;
    if (!(cin >> sum))
        return 0;

    static vector<long long> ways = prepare();

    cout << ways[sum] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}