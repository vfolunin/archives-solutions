#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSquaresSum(int n) {
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

    set<int> seen = { n };
    int res = 0;

    while (n > 1) {
        res++;
        n = digitSquaresSum(n);
        if (seen.count(n)) {
            cout << -1;
            return 0;
        }
        seen.insert(n);
    }

    cout << res;
}