#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCost(long long n, int base, vector<int> &cost) {
    int res = 0;
    while (n >= base) {
        res += cost[n % base];
        n /= base;
    }
    res += cost[n];
    return res;
}

void solve(int test) {
    vector<int> cost(36);
    for (int &c : cost)
        cin >> c;

    int queryCount;
    cin >> queryCount;

    if (test > 1)
        cout << "\n";
    cout << "Case " << test << ":\n";
    for (int i = 0; i < queryCount; i++) {
        long long n;
        cin >> n;

        int bestCost = 1e9;
        vector<int> bestBases;
        for (int base = 2; base <= 36; base++) {
            int curCost = getCost(n, base, cost);
            if (curCost < bestCost) {
                bestBases.clear();
                bestCost = curCost;
            }
            if (curCost == bestCost)
                bestBases.push_back(base);
        }

        cout << "Cheapest base(s) for number " << n << ":";
        for (int base : bestBases)
            cout << " " << base;
        cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}