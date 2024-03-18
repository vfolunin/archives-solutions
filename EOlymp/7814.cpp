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

    int n;
    cin >> n;

    int res = min(n / 10, n / 100 * 10 + n % 10);
    if (n % 100 / 10)
        res = min(res, n % 100);

    cout << res;
}