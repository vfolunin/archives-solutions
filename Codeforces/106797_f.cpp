#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    unordered_set<string> picked, dropped;
    for (int i = 0; i < queryCount; i++) {
        string type, arg;
        cin >> type >> arg;

        if (type == "pickup") {
            if (picked.contains(arg) || dropped.contains(arg)) {
                cout << "no";
                return 0;
            }
            picked.insert(arg);
        } else {
            if (!picked.contains(arg)) {
                cout << "no";
                return 0;
            }
            picked.erase(arg);
            dropped.insert(arg);
        }
    }

    cout << (picked.empty() ? "yes" : "no");
}