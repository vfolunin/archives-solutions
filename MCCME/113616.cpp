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

    int size, eventCount;
    cin >> size >> eventCount;

    vector<int> time(size, -1);
    set<pair<int, int>> order;
    for (int i = 0; i < size; i++)
        order.insert({ time[i], i });

    for (int t = 0; t < eventCount; t++) {
        int i;
        cin >> i;
        i--;

        order.erase({ time[i], i });
        time[i] = t;
        order.insert({ time[i], i });
    }

    for (auto &[t, i] : order)
        cout << i + 1 << " ";
}