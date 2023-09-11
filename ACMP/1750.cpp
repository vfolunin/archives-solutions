#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getDivisors(int n) {
    vector<int> divisors;

    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            divisors.push_back(d);
            if (d * d != n)
                divisors.push_back(n / d);
        }
    }

    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;

    if (!a) {
        cout << "1 " << b + 1;
        return 0;
    }

    for (int d : getDivisors(a)) {
        int h = d + 1, w = a / d + 1;
        if (2 * h * w - h - w == b) {
            cout << h << " " << w;
            return 0;
        }
    }
}