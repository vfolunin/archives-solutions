#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long c(int n, int k) {
    static vector<vector<long long>> memo(100, vector<long long>(100, -1));
    long long &res = memo[n][k];
    if (res != -1)
        return res;

    if (k == 0 || k == n)
        return res = 1;

    return res = c(n - 1, k) + c(n - 1, k - 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int count, takeCount;
    cin >> count >> takeCount;

    double res = 0;
    for (int minValue = 1; minValue <= count - takeCount + 1; minValue++)
        res += c(count - minValue, takeCount - 1) * (1LL << minValue);
    res /= c(count, takeCount);

    cout << fixed << res;
}