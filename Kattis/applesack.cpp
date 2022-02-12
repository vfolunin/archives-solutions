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

    int n, k;
    cin >> n >> k;

    int res = 0;
    while (n >= k) {
        res++;
        n = (n / k) * (k - 1) + max(0, n % k - 1);
    }

    cout << res + n + 1;
}