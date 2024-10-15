#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int a, int b) {
    static vector<vector<int>> memo(501, vector<int>(501, -1));
    if (memo[a][b] != -1)
        return memo[a][b];

    if (a == b)
        return memo[a][b] = 0;

    memo[a][b] = 1e9;
    for (int part = 1; part <= a - part; part++)
        memo[a][b] = min(memo[a][b], 1 + rec(part, b) + rec(a - part, b));
    for (int part = 1; part <= b - part; part++)
        memo[a][b] = min(memo[a][b], 1 + rec(a, part) + rec(a, b - part));
    return memo[a][b];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    cout << rec(a, b);
}