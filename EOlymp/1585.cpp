#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long c(int n, int k) {
    if (n < k)
        return 0;

    static vector<vector<long long>> memo(20, vector<long long>(20, -1));
    long long &res = memo[n][k];
    if (res != -1)
        return res;

    if (k == 0 || k == n)
        return res = 1;

    return res = c(n - 1, k) + c(n - 1, k - 1);
}

bool solve() {
    int maxValue, take, threshold;
    if (!(cin >> maxValue >> take >> threshold))
        return 0;

    double res = 0;
    for (int equal = threshold; equal <= take; equal++)
        res += c(take, equal) * c(maxValue - take, take - equal);
    res /= c(maxValue, take);

    cout.precision(4);
    cout << fixed << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}