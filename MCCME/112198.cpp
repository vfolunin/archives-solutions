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

bool isGood(int value) {
    int sum = digitSum(value);
    for (int i = 2; i < 10; i++)
        if (digitSum(value * i) != sum)
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    bool found = 0;
    for (int i = l; i <= r; i++) {
        if (isGood(i)) {
            cout << i << " ";
            found = 1;
        }
    }

    if (!found)
        cout << 0;
}