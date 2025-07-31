#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long c(int n, int k) {
    static vector<vector<long long>> memo(1000, vector<long long>(1000, -1));
    long long &res = memo[n][k];
    if (res != -1)
        return res;

    if (k == 0 || k == n)
        return res = 1;

    return res = c(n - 1, k) + c(n - 1, k - 1);
}

void solve() {
    int sideThreshold, sideCount, rollThreshold, rollCount, factor;
    cin >> sideThreshold >> sideCount >> rollThreshold >> rollCount >> factor;

    double probability = 0;
    for (int winRollCount = rollThreshold; winRollCount <= rollCount; winRollCount++)
        probability += c(rollCount, winRollCount) *
                       pow((sideCount - sideThreshold + 1.0) / sideCount, winRollCount) *
                       pow((sideThreshold - 1.0) / sideCount, rollCount - winRollCount);
    
    cout << (probability * factor > 1 ? "yes\n" : "no\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}