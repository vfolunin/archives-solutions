#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<vector<long long>> prepare() {
    vector<vector<long long>> ways(302, vector<long long>(302));
    for (int last = 0; last <= 301; last++)
        ways[0][last] = 1;

    for (int sum = 1; sum <= 301; sum++) {
        for (int last = 1; last <= 301; last++) {
            ways[sum][last] = ways[sum][last - 1];
            if (sum >= last)
                ways[sum][last] += ways[sum - last][last];
        }
    }

    return ways;
}

bool solve() {
    int n, a = -1, b = -1;
    if (!(cin >> n))
        return 0;

    if (cin.peek() == ' ')
        cin >> a;
    a = min(a, 301);
    if (cin.peek() == ' ')
        cin >> b;
    b = min(b, 301);

    static vector<vector<long long>> ways = prepare();

    if (a == -1)
        cout << ways[n][300] << "\n";
    else if (b == -1)
        cout << ways[n][a] << "\n";
    else
        cout << ways[n][b] - (a ? ways[n][a - 1] : 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}