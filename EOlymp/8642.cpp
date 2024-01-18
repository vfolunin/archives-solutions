#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long binPow(long long x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x;
    long long r = binPow(x, p / 2);
    return r * r;
}

bool isArmstrongNumber(long long value) {
    string digits = to_string(value);
    long long sum = 0;
    for (char d : digits)
        sum += binPow(d - '0', digits.size());
    return sum == value;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int l, r;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
        if (isArmstrongNumber(i))
            cout << i << " ";
}