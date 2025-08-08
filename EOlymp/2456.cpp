#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int queryCount;
    cin >> queryCount;

    map<int, int> sell, buy;
    int stockPrice = -1e9;

    for (int i = 0; i < queryCount; i++) {
        string type, buf;
        int amount, price;
        cin >> type >> amount >> buf >> buf >> price;

        if (type == "sell")
            sell[price] += amount;
        else
            buy[price] += amount;

        while (!sell.empty() && !buy.empty() && sell.begin()->first <= buy.rbegin()->first) {
            stockPrice = sell.begin()->first;
            int delta = min(sell.begin()->second, buy.rbegin()->second);
            if (!(sell.begin()->second -= delta))
                sell.erase(sell.begin());
            if (!(buy.rbegin()->second -= delta))
                buy.erase(prev(buy.end()));
        }

        if (!sell.empty())
            cout << sell.begin()->first << " ";
        else
            cout << "- ";
        if (!buy.empty())
            cout << buy.rbegin()->first << " ";
        else
            cout << "- ";
        if (stockPrice != -1e9)
            cout << stockPrice << "\n";
        else
            cout << "-\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}