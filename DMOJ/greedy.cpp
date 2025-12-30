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

    int size, targetCount;
    cin >> size >> targetCount;

    vector<pair<int, int>> pairs(size);
    for (auto &[price, count] : pairs)
        cin >> price >> count;

    sort(pairs.begin(), pairs.end());

    long long res = 0;
    for (auto &[price, count] : pairs) {
        long long delta = min(count, targetCount);
        targetCount -= delta;
        res += price * delta;
    }

    cout << res;
}