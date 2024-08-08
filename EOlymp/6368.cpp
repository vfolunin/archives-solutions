#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int digitSquareSum(int n) {
    int res = 0;
    while (n) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    unordered_set<int> seen;
    for (; n != 1 && !seen.count(n); n = digitSquareSum(n))
        seen.insert(n);

    cout << (n == 1 ? "HAPPY" : "SAD");
}