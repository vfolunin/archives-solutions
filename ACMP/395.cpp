#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitProduct(int n) {
    int res = 1;
    while (n) {
        res *= n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    int res = 0;
    for (int i = l; i <= r; i++) {
        int product = digitProduct(i);
        res += product && i % product == 0;
    }

    cout << res;
}