#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(int n) {
    int res = 0;
    while (n > 9) {
        res += n % 10;
        n /= 10;
    }
    return res + n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r, sum;
    cin >> l >> r >> sum;

    while (digitSum(l) != sum)
        l++;

    while (digitSum(r) != sum)
        r--;

    cout << l << "\n" << r;
}