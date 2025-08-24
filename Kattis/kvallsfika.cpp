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

    int size, money, limit;
    cin >> size >> money >> limit;

    vector<pair<int, int>> pairs(size);
    for (auto &[price, type] : pairs)
        cin >> price;
    for (auto &[price, type] : pairs)
        cin >> type;

    sort(pairs.begin(), pairs.end());
    unordered_map<int, int> count;
    int res = 0;

    for (auto &[price, type] : pairs) {
        if (money >= price && count[type] < limit) {
            money -= price;
            count[type]++;
            res++;
        }
    }

    cout << res;
}