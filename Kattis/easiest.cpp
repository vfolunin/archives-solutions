#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    if (n < 10)
        return n;
    return digitSum(n / 10) + n % 10;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    int nSum = digitSum(n), res = 11;
    while (digitSum(n * res) != nSum)
        res++;

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}