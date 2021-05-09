#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const vector<int> coinValue = { 5, 10, 20, 50, 100, 200 };

int coins(int sum) {
    int res = 0;
    for (int i = 5; i >= 0 && sum; i--) {
        int delta = sum / coinValue[i];
        res += delta;
        sum -= delta * coinValue[i];
    }
    return sum ? 1e9 : res;
}

int coins(int sum, vector<int> &coinCount) {
    int res = 0;
    for (int i = 5; i >= 0 && sum; i--) {
        int delta = min(coinCount[i], sum / coinValue[i]);
        res += delta;
        sum -= delta * coinValue[i];
    }
    return sum ? 1e9 : res;
}

bool solve() {
    vector<int> coinCount(6);
    for (int &c : coinCount)
        cin >> c;

    if (!*max_element(coinCount.begin(), coinCount.end()))
        return 0;

    double s;
    cin >> s;
    int sum = s * 100 + 1e-9;

    int res = coins(sum, coinCount);
    for (int add = 1; add <= 1000; add++)
        res = min(res, coins(sum + add, coinCount) + coins(add));

    cout << setw(3) << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}