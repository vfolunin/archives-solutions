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

    long long a, b;
    cin >> a >> b;

    long long l = 0, r = 1e9;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (m * m < a * b)
            l = m;
        else
            r = m;
    }

    cout << (r * r == a * b ? r : 0);
}