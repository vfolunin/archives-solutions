#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int bankCount, opCount;
    cin >> bankCount >> opCount;

    if (!bankCount && !opCount)
        return 0;

    vector<int> money(bankCount);
    for (int &x : money)
        cin >> x;

    for (int i = 0; i < opCount; i++) {
        int bankA, bankB, moneyAmount;
        cin >> bankA >> bankB >> moneyAmount;
        money[bankA - 1] -= moneyAmount;
        money[bankB - 1] += moneyAmount;
    }

    cout << (*min_element(money.begin(), money.end()) >= 0 ? "S\n" : "N\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}