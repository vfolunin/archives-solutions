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

    int size, targetSize;
    cin >> size >> targetSize;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    if (count.size() <= targetSize) {
        cout << targetSize - count.size();
        return 0;
    }

    multiset<int> counts;
    for (auto &[value, count] : count)
        counts.insert(count);

    int res = 0;
    while (counts.size() > targetSize) {
        res += *counts.begin();
        counts.erase(counts.begin());
    }

    cout << res;
}