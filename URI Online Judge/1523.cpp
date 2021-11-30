#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int carCount, capacity;
    cin >> carCount >> capacity;

    if (!carCount && !capacity)
        return 0;

    vector<pair<int, int>> events;
    for (int i = 0; i < carCount; i++) {
        int l, r;
        cin >> l >> r;
        events.push_back({ l, (i + 1) });
        events.push_back({ r, -(i + 1) });
    }

    sort(events.begin(), events.end());
    vector<int> stack;

    for (auto &[time, type] : events) {
        if (type > 0) {
            if (stack.size() == capacity) {
                cout << "Nao\n";
                return 1;
            }
            stack.push_back(type);
        } else {
            if (stack.empty() || stack.back() != -type) {
                cout << "Nao\n";
                return 1;
            }
            stack.pop_back();
        }
    }

    cout << "Sim\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}