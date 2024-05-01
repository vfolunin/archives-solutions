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

    int size;
    cin >> size;

    vector<int> a(size);
    unordered_map<int, int> count;
    for (int &value : a) {
        cin >> value;
        count[value]++;
    }

    for (int value : a) {
        int res = 0;

        for (auto &[part, partCount] : count)
            if (auto it = count.find(value - part); it != count.end() && part * 2 < value)
                res += partCount * it->second;

        if (auto it = count.find(value / 2); it != count.end() && value % 2 == 0)
            res += it->second * (it->second - 1) / 2;

        cout << res << "\n";
    }
}