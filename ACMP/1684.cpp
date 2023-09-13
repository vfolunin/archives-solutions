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

    if (d % 2) {
        cout << "0 " << d;
    } else {
        cout << d << " ";
        while (d % 2 == 0)
            d /= 2;
        cout << d;
    }
}