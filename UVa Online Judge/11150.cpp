#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> simulate(int bottles) {
    int totalBottles = bottles;
    while (bottles >= 3) {
        totalBottles += bottles / 3;
        bottles = bottles / 3 + bottles % 3;
    }
    return { totalBottles, bottles };
}

bool solve() {
    int initialBottles;
    if (!(cin >> initialBottles))
        return 0;

    auto [res, _] = simulate(initialBottles);

    auto [total1, residual1] = simulate(initialBottles + 1);
    if (residual1 >= 1 && total1 - 1 > res)
        res = total1 - 1;

    auto [total2, residual2] = simulate(initialBottles + 2);
    if (residual2 == 2 && total2 - 2 > res)
        res = total2 - 2;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}