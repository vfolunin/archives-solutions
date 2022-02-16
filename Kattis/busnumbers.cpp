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

    int busCount;
    cin >> busCount;

    vector<int> buses(busCount);
    for (int &bus : buses)
        cin >> bus;

    sort(buses.begin(), buses.end());

    vector<pair<int, int>> ranges;
    for (int bus : buses) {
        if (ranges.empty() || ranges.back().second + 1 != bus)
            ranges.push_back({ bus, bus });
        else
            ranges.back().second++;
    }

    for (auto [l, r] : ranges) {
        if (l + 1 < r)
            cout << l << "-";
        else if (l + 1 == r)
            cout << l << " ";
        cout << r << " ";
    }
}