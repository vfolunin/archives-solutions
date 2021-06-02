#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int nth(long long n) {
    if (n < 10)
        return n;
    n -= 10;

    long long len = 2, count = 90;
    while (n >= count * len) {
        n -= count * len;
        len++;
        count *= 10;
    }

    long long number = 1;
    for (int i = 1; i < len; i++)
        number *= 10;
    number += n / len;

    n = len - 1 - n % len;
    for (int i = 0; i < n; i++)
        number /= 10;

    return number % 10;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        long long n;
        cin >> n;

        cout << nth(n) << "\n";
    }
}