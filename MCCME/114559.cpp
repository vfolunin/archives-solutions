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

    long long t;
    vector<long long> a(3);
    cin >> t >> a[0] >> a[1] >> a[2];

    long long res = 1e18;
    for (long long value : a)
        res = min(res, ((t + value - 1) / value * value - t) % value);
    
    cout << res;
}