#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    double den = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        den += sin(i);
        res += 1 / den;
    }

    cout << fixed << res;
}