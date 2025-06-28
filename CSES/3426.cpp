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

    int size, windowSize;
    cin >> size >> windowSize;

    vector<int> a(size);
    long long b, c;
    int mod;
    cin >> a[0] >> b >> c >> mod;

    for (int i = 1; i < size; i++)
        a[i] = (a[i - 1] * b + c) % mod;

    int cur = 0;
    for (int i = 0; i < windowSize; i++)
        cur ^= a[i];

    int res = cur;
    for (int i = windowSize; i < size; i++) {
        cur ^= a[i] ^ a[i - windowSize];
        res ^= cur;
    }

    cout << res;
}