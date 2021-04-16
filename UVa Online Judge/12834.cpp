#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int placeCount, skipCount;
    cin >> placeCount >> skipCount;

    vector<int> profit(placeCount);
    for (int i = 0; i < placeCount; i++) {
        int x;
        cin >> x;
        profit[i] -= x;
    }
    for (int i = 0; i < placeCount; i++) {
        int x;
        cin >> x;
        profit[i] += x;
    }

    sort(profit.begin(), profit.end());

    long long totalProfit = 0;
    for (int test = 0; test < placeCount; test++) {
        if (profit[test] < 0 && test < skipCount)
            continue;
        totalProfit += profit[test];
    }

    cout << "Case " << test << ": ";
    if (totalProfit > 0)
        cout << totalProfit << "\n";
    else
        cout << "No Profit\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}