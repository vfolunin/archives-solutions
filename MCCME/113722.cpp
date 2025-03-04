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

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int res = 0;
    if (n > 1)
        res += min(a, b);
    if (n > 2)
        res += (n - 2) * min({ a, b, c });

    cout << res;
}