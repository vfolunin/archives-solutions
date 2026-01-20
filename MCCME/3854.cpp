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

    int points, count5, count10;
    cin >> points >> count5 >> count10;

    points -= count5 * 5;
    points -= count10 * 10;

    int res = count5 * 3 + count10 * 4;
    points -= min(res * 3, points);
    res += (points + 2) / 3;

    cout << res;
}