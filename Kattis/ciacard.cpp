#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getBonus(int money) {
    static vector<int> to = { 1999, 3999, 5999, 7999, (int)2e9 };
    static vector<int> bonus = { 0, 25, 50, 75, 150 };
    return bonus[lower_bound(to.begin(), to.end(), money) - to.begin()];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int money;
    cin >> money;

    int res = 0;
    for (int a = 0, b = money; a <= b && a <= 8000; a++, b--)
        res = max(res, getBonus(a) + getBonus(b));

    cout << res;
}