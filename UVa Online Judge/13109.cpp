#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int elephantCount, maxWeight;
    cin >> elephantCount >> maxWeight;

    vector<long long> weight(elephantCount);
    for (long long &w : weight)
        cin >> w;

    sort(weight.begin(), weight.end());

    long long totalWeight = 0;
    int res = 0;
    while (res < elephantCount && totalWeight + weight[res] <= maxWeight) {
        totalWeight += weight[res];
        res++;
    }

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}