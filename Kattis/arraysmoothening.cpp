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

    int size, opCount;
    cin >> size >> opCount;

    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value]++;
    }

    multiset<int> counts;
    for (auto &[value, count] : count)
        counts.insert(count);

    for (int i = 0; i < opCount; i++) {
        int count = *prev(counts.end());
        counts.erase(prev(counts.end()));
        counts.insert(max(count - 1, 0));
    }

    cout << *prev(counts.end());
}