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

    set<pair<int, int>> pairs;

    for (int op; cin >> op && op; ) {
        if (op == 1) {
            int key, priority;
            cin >> key >> priority;
            pairs.insert({ priority, key });
        } else if (op == 2) {
            if (!pairs.empty()) {
                cout << prev(pairs.end())->second << "\n";
                pairs.erase(prev(pairs.end()));
            } else {
                cout << "0\n";
            }
        } else {
            if (!pairs.empty()) {
                cout << pairs.begin()->second << "\n";
                pairs.erase(pairs.begin());
            } else {
                cout << "0\n";
            }
        }
    }
}