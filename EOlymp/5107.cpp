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

    int passengerCount, stopCount;
    cin >> passengerCount >> stopCount;

    map<int, set<int>> stops;
    for (int i = 0; i < passengerCount; i++) {
        int from, to;
        cin >> from >> to;
        stops[from].insert(to);
    }

    set<int> res = { 1 };
    for (auto it = res.begin(); it != res.end(); it++)
        res.insert(stops[*it].begin(), stops[*it].end());

    cout << res.size() << "\n";
    for (int value : res)
        cout << value << "\n";
}