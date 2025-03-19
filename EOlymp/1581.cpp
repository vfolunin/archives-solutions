#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int targetSum;
    if (!(cin >> targetSum))
        return 0;

    vector<double> res(targetSum + 1);
    for (int sum = 1; sum <= targetSum; sum++) {
        for (int toss = 1; toss <= 6 && toss <= sum; toss++)
            res[sum] += res[sum - toss];
        res[sum] = res[sum] / 6 + 1;
    }

    cout.precision(4);
    cout << fixed << res[targetSum] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}