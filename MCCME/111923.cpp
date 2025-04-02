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

    for (long long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            cout << d << " " << n / d;
            return 0;
        }
    }

    cout << "PRIME";
}