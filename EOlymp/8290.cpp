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

    int a, b;
    cin >> a >> b;

    int sum = (a + b) / gcd(a, b);
    if (sum & (sum - 1)) {
        cout << -1;
        return 0;
    }

    int res = 0;
    while (a != b) {
        if (a > b)
            swap(a, b);
        b -= a;
        a *= 2;
        res++;
    }

    cout << res;
}