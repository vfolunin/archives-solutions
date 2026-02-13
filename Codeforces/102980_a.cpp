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

    int size, sum;
    cin >> size >> sum;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value]++;
    }

    int res = 0;
    for (auto &[l, countL] : count)
        if (l < sum - l && count.count(sum - l))
            res += min(count[l], count[sum - l]);

    if (sum % 2 == 0 && count.count(sum / 2))
        res += count[sum / 2] - 1;

    cout << res;
}