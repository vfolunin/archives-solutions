#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

long long count(long long n, long long d) {
    return n >= 0 ? n / d + 1 : 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b, c, dayDuration, dayIndex;
    cin >> a >> b >> c >> dayDuration >> dayIndex;

    long long d = lcm(lcm(a, b), c);
    long long l = (dayIndex - 1) * dayDuration, r = dayIndex * dayDuration - 1;

    cout << count(r, d) - count(l - 1, d);
}