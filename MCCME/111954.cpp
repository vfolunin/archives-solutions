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

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;
    }

    set<pair<int, int>> counts;
    for (auto &[value, count] : count)
        counts.insert({ count, value });

    if (prev(counts.end())->first * 2 - 1 > size) {
        cout << 0;
        return 0;
    }

    int prevValue = 0;
    for (int i = 0; i < size; i++) {
        auto [count, value] = *prev(counts.end());
        counts.erase(prev(counts.end()));

        if (prevValue != value) {
            cout << value << " ";

            if (count)
                counts.insert({ count - 1, value });
            prevValue = value;
        } else {
            auto [secondCount, secondValue] = *prev(counts.end());
            counts.erase(prev(counts.end()));
            counts.insert({ count, value });

            cout << secondValue << " ";

            if (secondCount)
                counts.insert({ secondCount - 1, secondValue });
            prevValue = secondValue;
        }
    }
}