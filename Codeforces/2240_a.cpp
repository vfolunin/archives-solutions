#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int limit, size;
    cin >> limit >> size;

    int res = 0;
    for (int price = 1; price <= limit; price *= 2) {
        int count = min(limit / price, size);
        limit -= count * price;
        res += count;
    }

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