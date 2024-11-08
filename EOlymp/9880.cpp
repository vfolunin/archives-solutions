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
    cin >> n;

    int res = 1e9;
    for (int a = 1; a * a * a <= n; a++) {
        for (int b = a; a * b * b <= n; b++) {
            if (n % (a * b))
                continue;
            int c = n / a / b;
            res = min(res, 2 * (a * b + a * c + b * c));
        }
    }

    cout << res;
}