#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sumOfDigitSquares(int n) {
    int res = 0;
    while (n > 9) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    res += n * n;
    return res;
}

void solve(int test) {
    int n;
    cin >> n;

    int res = sumOfDigitSquares(n);
    while (res > 9)
        res = sumOfDigitSquares(res);
    
    cout << "Case #" << test << ": " << n << " is ";
    cout << (res == 1 ? "a Happy" : "an Unhappy") << " number.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}