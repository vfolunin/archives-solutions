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

    long long count, price, delta, money;
    cin >> count >> price >> delta >> money;

    long long res = 0;
    while (money >= count * price) {
        money -= count * price;
        res += count;
        price += delta;
    }
    res += money / price;

    cout << res;
}