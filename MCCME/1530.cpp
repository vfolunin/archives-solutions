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

    int n;
    double x;
    cin >> n >> x;

    double res = 1, num = 1, den = 1;
    for (int i = 0; i < 2 * n; i += 2) {
        num *= x * x;
        den *= (i + 1) * (i + 2);
        res += (i / 2 % 2 ? 1 : -1) * num / den;
    }

    cout << fixed << res;
}