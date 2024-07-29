#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long h, w, k;
    cin >> h >> w >> k;

    long long n = (h * w - (h + w - gcd(h, w))) / 2;
    n = (k - n % k) % k;

    cout << n;
}