#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int digitSum(long long n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long reverse(long long n) {
    long long res = 0;
    while (n) {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

long long transform(long long value) {
    for (int i = 0; i < 2; i++) {
        if (digitSum(value) > 10)
            value = value * 100 + value % 100;
        else
            value = reverse(value);
    }
    return value;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int limit;
    cin >> limit;

    int res = 1;
    while (transform(res) < limit)
        res++;

    cout << res;
}