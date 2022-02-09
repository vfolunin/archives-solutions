#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, b;
    cin >> a >> b;

    long long d = gcd(a, b);
    if (a / d % 2 == 0 || b / d % 2 == 0)
        d = 0;

    cout << d;
}