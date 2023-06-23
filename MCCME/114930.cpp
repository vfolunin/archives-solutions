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

    long long n, k, l, r;
    cin >> n >> k >> l >> r;

    cout << max(0LL, n - k * r) << " " << n - l;
}