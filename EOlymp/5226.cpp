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

    int size, mod;
    cin >> size >> mod;

    vector<vector<int>> a(mod);
    for (int i = 0; i < size; i++)
        cin >> a[i % mod].emplace_back();
    
    long long res = 0;
    for (vector<int> &a : a) {
        if (a.size() < 2)
            continue;

        vector<long long> cost(a.size());
        cost[1] = max(0, a[0] + a[1]);
        for (int i = 2; i < a.size(); i++)
            cost[i] = max(cost[i - 1], cost[i - 2] + a[i - 1] + a[i]);

        res += cost.back();
    }

    cout << res;
}