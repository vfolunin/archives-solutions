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

    int size, delta;
    cin >> size >> delta;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    long long res = 0;
    for (auto &[value, _] : count)
        if (count.count(value + delta))
            res += 1LL * count[value] * count[value + delta];

    cout << res;
}