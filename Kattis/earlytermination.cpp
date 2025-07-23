#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b, limit;
    cin >> a >> b >> limit;

    while (a && b && (a > (limit + a - 1) / a || b > (limit + b - 1) / b)) {
        long long t = a % b;
        a = b;
        b = t;
    }

    if (a < b)
        swap(a, b);

    cout << a << " " << b;
}