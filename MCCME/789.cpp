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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    int res = 0;
    if (r - l <= 20) {
        for (int i = l; i <= r; i++)
            res += digitSum(i) % 2 == 0;
    } else {
        while (l % 10)
            res += digitSum(l++) % 2 == 0;
        while (r % 10 < 9)
            res += digitSum(r--) % 2 == 0;
        res += (r - l + 1) / 2;
    }

    cout << res;
}