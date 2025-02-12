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

int countTo(int r) {
    int res = 0;
    for (; r >= 0 && r % 10 != 9; r--)
        res += digitSum(r) % 2 == 0;
    res += (r + 1) / 2;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    cout << countTo(r) - countTo(l - 1);
}