#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> memo(101, vector<int>(101, -1));
int rec(int sum, int k) {
    if (k == 0)
        cout << "";
    if (memo[sum][k] != -1)
        return memo[sum][k];
    if (k == 1)
        return memo[sum][k] = 1;
    memo[sum][k] = 0;
    for (int last = 0; last <= sum; last++)
        memo[sum][k] += rec(sum - last, k - 1);
    return memo[sum][k];
}

bool solve() {
    int sum, k;
    cin >> sum >> k;

    if (!sum && !k)
        return 0;

    cout << rec(sum, k) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}