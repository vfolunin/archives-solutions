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

    long long money, price1, price2, change2;
    cin >> money >> price1 >> price2 >> change2;

    if (price1 <= price2 - change2 || money < price2) {
        cout << money / price1;
    } else if (money >= price2) {
        long long res = 1 + (money - price2) / (price2 - change2);
        money -= res * (price2 - change2);
        res += money / price1;

        cout << res;
    } else {
        cout << 0;
    }
}