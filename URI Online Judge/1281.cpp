#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int priceCount;
    cin >> priceCount;

    map<string, double> prices;
    for (int i = 0; i < priceCount; i++) {
        string name;
        cin >> name >> prices[name];
    }

    int itemCount;
    cin >> itemCount;

    double totalPrice = 0;
    for (int i = 0; i < itemCount; i++) {
        string name;
        int amount;
        cin >> name >> amount;
        totalPrice += prices[name] * amount;
    }

    cout.precision(2);
    cout << "R$ " << fixed << totalPrice << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}