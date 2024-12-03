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

    double delta, percentage;
    cin >> delta >> percentage;

    double cur = 0, res = 0;
    for (int i = 0; i < 1e5; i++) {
        cur += delta;
        res = max(res, cur);
        cur *= (100 - percentage) / 100;
    }

    cout << fixed << res;
}