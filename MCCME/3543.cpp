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

    long long a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int res = 0;
    for (long long x = 0; x <= 1000; x++)
        res += x != e && ((a * x + b) * x + c) * x + d == 0;

    cout << res;
}