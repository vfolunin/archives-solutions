#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    vector<int> weight(1 << n);
    for (int &w : weight)
        cin >> w;

    vector<int> potency(1 << n);
    for (int mask = 0; mask < potency.size(); mask++)
        for (int bit = 0; bit < n; bit++)
            potency[mask] += weight[mask ^ (1 << bit)];
    
    int maxSum = 0;
    for (int mask = 0; mask < potency.size(); mask++)
        for (int bit = 0; bit < n; bit++)
            maxSum = max(maxSum, potency[mask] + potency[mask ^ (1 << bit)]);

    cout << maxSum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}