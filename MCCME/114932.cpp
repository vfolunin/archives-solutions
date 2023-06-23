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

    long long a, b, n, c;
    cin >> a >> b >> n >> c;

    long long res = n * b;
    for (int ka = 1; ka <= n; ka++)
        res = min(res, ka * a + max(0LL, n - ka - ka / c) * b);
    
    cout << res;
}