#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitProduct(int n) {
    int res = 1;
    while (n > 9) {
        res *= n % 10;
        n /= 10;
    }
    return res * n;
}

int f(int n) {
    return n > 9 ? 1 + f(digitProduct(n)) : 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int n; cin >> n; )
        cout << f(n) << "\n";
}