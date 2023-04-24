#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int f(int n) {
    int res = n;
    while (n >= 10) {
        n = digitSum(n);
        res += n;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = max(1, n - 10000); i <= n; i++) {
        if (f(i) == n) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}