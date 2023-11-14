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

    int resSum = 1e9, resCount = 0;
    for (int i = l; i <= r; i++) {
        int sum = digitSum(i);
        if (resSum > sum) {
            resSum = sum;
            resCount = 1;
        } else if (resSum == sum) {
            resCount++;
        }
    }

    cout << resCount;
}