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

    long long n, k, t;
    cin >> n >> k >> t;

    long long l1 = 1, r1 = n;
    long long l2 = t - k + 1, r2 = t;

    cout << min(r1, r2) - max(l1, l2) + 1;
}