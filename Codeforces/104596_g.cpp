#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool binsearch(vector<long long> &a, long long value) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (value == a[m])
            return 1;
        if (value < a[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    long long mod, x, y;
    cin >> size >> mod >> x >> y;

    vector<long long> a(size + 1);
    cin >> a[0];
    for (int i = 1; i <= size; i++)
        a[i] = (a[i - 1] * x + y) % mod;
    a.erase(a.begin());

    int res = 0;
    for (long long value : a)
        res += binsearch(a, value);

    cout << res;
}