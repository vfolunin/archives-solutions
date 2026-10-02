#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

void read(int level, unordered_map<long long, int> &count) {
    if (cin.peek() == '[') {
        cin.get();
        read(level + 1, count);
        cin.get();
        read(level + 1, count);
        cin.get();
    } else {
        int value;
        cin >> value;

        count[(1LL << level) * value]++;
    }
}

void solve() {
    unordered_map<long long, int> count;
    cin.ignore();
    read(0, count);

    int totalCount = 0, maxCount = 0;
    for (auto &[_, count] : count) {
        totalCount += count;
        maxCount = max(maxCount, count);
    }

    cout << totalCount - maxCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}