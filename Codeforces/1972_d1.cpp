#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int aLimit, bLimit;
    cin >> aLimit >> bLimit;

    int res = -1;
    for (long long b = 1; b <= bLimit; b++)
        res += (aLimit + b) / (b * b);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}