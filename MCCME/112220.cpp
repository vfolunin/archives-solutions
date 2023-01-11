#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> gcd(int a, int b) {
    if (a < b)
        return gcd(b, a);
    if (!b)
        return { a, 0 };
    auto [d, stepCount] = gcd(b, a % b);
    return { d, stepCount + 1 };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    auto [d, stepCount] = gcd(a, b);

    cout << d << " " << stepCount;
}