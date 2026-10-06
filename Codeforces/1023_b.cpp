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

    long long n, sum;
    cin >> n >> sum;

    long long l = max(sum - n, 1LL);
    long long r = min(sum - l, n);

    cout << max(r - l + 1, 0LL) / 2;
}