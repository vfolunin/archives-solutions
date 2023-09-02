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

    long long resArea = 1e18;
    int resA, resB, resC;

    for (int a = max(1, n / 3 - 5); a + a + a < n; a++) {
        for (int b = a + 1; a + b + b < n; b++) {
            int c = n - a - b;
            long long area = 1LL * a * a + 1LL * b * b + 1LL * c * c;

            if (resArea > area) {
                resArea = area;
                resA = a;
                resB = b;
                resC = c;
            }
        }
    }

    cout << resA << " " << resB << " " << resC;
}