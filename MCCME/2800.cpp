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

    int price, r, k;
    cin >> price >> r >> k;

    int money = r * 100 + k, resMoney = money, res = 0;
    for (int i = 1; i < 2e4 && money >= price; i++) {
        money -= price;
        money = money % 100 * 100 + money / 100;
        if (resMoney < money) {
            resMoney = money;
            res = i;
        }
    }

    cout << res;
}