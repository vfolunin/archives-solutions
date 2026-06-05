#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long count, price1, price3;
    cin >> count >> price1 >> price3;

    if (price1 * 3 < price3)
        cout << count * price1 << "\n";
    else
        cout << (count / 3 * price3) + min(count % 3 * price1, price3) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}