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

    int queryCount;
    cin >> queryCount;

    unordered_map<string, int> amount;

    for (int i = 0; i < queryCount; i++) {
        int type;
        string id;
        cin >> type >> id;

        if (type == 1) {
            int delta;
            cin >> delta;
            amount[id] += delta;
        } else {
            if (amount.count(id))
                cout << amount[id] << "\n";
            else
                cout << "ERROR\n";
        }
    }
}