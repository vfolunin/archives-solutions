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

    long long t, t1, k1, t2, k2;
    cin >> t >> t1 >> k1 >> t2 >> k2;

    long long kab = max((t - t1) * k1, 0LL) + max((t - t1 - t2) * k2, 0LL);
    long long kba = max((t - t2) * k2, 0LL) + max((t - t2 - t1) * k1, 0LL);

    cout << max(kab, kba);
}