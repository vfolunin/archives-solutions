#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int units, int bars, int maxWidth) {
    if (units <= 0)
        return 0;
    
    static vector<vector<vector<long long>>> memo(60, vector<vector<long long>>(60, vector<long long>(60, -1)));
    if (memo[units][bars][maxWidth] != -1)
        return memo[units][bars][maxWidth];

    if (bars == 1)
        return memo[units][bars][maxWidth] = (units <= maxWidth);
    
    long long res = 0;
    for (int lastWidth = 1; lastWidth <= maxWidth; lastWidth++)
        res += rec(units - lastWidth, bars - 1, maxWidth);
    return memo[units][bars][maxWidth] = res;
}

bool solve() {
    int units, bars, maxWidth;
    if (!(cin >> units >> bars >> maxWidth))
        return 0;

    cout << rec(units, bars, maxWidth) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}