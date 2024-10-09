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

long long transform(long long value) {
    for (int i = 0; i < 3; i++)
        value = value * 2 + digitSum(value) % 2;
    return value;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limit;
    cin >> limit;

    int res = 1e9;
    for (int i = 1; i < 2e5; i++) {
        int value = transform(i);
        if (value > limit)
            res = min(res, value);
    }

    cout << res;
}