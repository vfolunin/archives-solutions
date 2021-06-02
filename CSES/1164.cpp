#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Customer {
    int index, l, r, room;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int customerCount;
    cin >> customerCount;

    vector<Customer> customers(customerCount);
    for (int i = 0; i < customerCount; i++) {
        customers[i].index = i;
        cin >> customers[i].l >> customers[i].r;
    }

    sort(customers.begin(), customers.end(), [](auto &a, auto &b) { return a.l < b.l; });
    set<pair<int, int>> roomFree = { { 0, 0 } };

    for (auto &[_, l, r, room] : customers) {
        if (roomFree.begin()->first < l) {
            room = roomFree.begin()->second;
            roomFree.erase(roomFree.begin());
            roomFree.insert({ r, room });
        } else {
            room = roomFree.size();
            roomFree.insert({ r, roomFree.size() });
        }
    }

    sort(customers.begin(), customers.end(), [](auto &a, auto &b) { return a.index < b.index; });

    cout << roomFree.size() << "\n";
    for (auto c : customers)
        cout << c.room + 1 << " ";
}