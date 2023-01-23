#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long getSum(long long l, long long r) {
    return (l + r) * (r - l + 1) / 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long target, from;
    cin >> target >> from;

    long long l = 0, r = 1;
    while (getSum(from, from + r - 1) < target)
        r *= 2;

    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (getSum(from, from + m - 1) < target)
            l = m;
        else
            r = m;
    }

    cout << r;
}