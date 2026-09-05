#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int size, penalty;
    long long targetSum;
    cin >> size >> penalty >> targetSum;

    long long prefixSum = 0;
    unordered_map<long long, int> seen = { { prefixSum, -1 } };
    pair<int, int> res = { size, size };

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        prefixSum += value - penalty;
        if (auto it = seen.find(prefixSum - targetSum); it != seen.end())
            res = min(res, { it->second + 1, i });

        if (auto it = seen.find(prefixSum); it == seen.end())
            seen[prefixSum] = i;
    }

    if (res.first != size)
        cout << res.first << " " << res.second;
    else
        cout << -1;
}