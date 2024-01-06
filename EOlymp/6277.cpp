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

    int money;
    cin >> money;
    money *= 100;

    int res = 0;
    while (money >= 120) {
        int delta = money / 120;
        res += delta;
        money = delta * 20 + money % 120;
    }

    cout << res;
}