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

    int ticketCount, customerCount;
    cin >> ticketCount >> customerCount;

    multiset<int> tickets;
    for (int i = 0; i < ticketCount; i++) {
        int price;
        cin >> price;
        tickets.insert(price);
    }

    for (int i = 0; i < customerCount; i++) {
        int price;
        cin >> price;

        auto it = tickets.upper_bound(price);
        if (it == tickets.begin()) {
            cout << "-1 ";
        } else {
            cout << *--it << " ";
            tickets.erase(it);
        }
    }
}