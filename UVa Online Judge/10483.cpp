#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long read() {
    long long whole, frac;
    char dot;
    cin >> whole >> dot >> frac;
    return whole * 100 + frac;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long l = read(), r = read();

    cout.precision(2);
    cout << fixed;

    vector<vector<long long>> res;
    for (long long a = 1; a <= r; a++) {
        for (long long b = a; a + b <= r && a * b <= r * 100; b++) {
            if (a * b == 10000)
                continue;
            long long c = 10000 * (a + b) / (a * b - 10000);
            long long sum = a + b + c, prod = a * b * c;
            if (b <= c && l <= sum && sum <= r && sum * 10000 == prod)
                res.push_back({ sum, a, b, c });
        }
    }

    sort(res.begin(), res.end());
    for (auto &v : res) {
        cout << v[0] / 100.0 << " = ";
        cout << v[1] / 100.0 << " + " << v[2] / 100.0 << " + " << v[3] / 100.0 << " = ";
        cout << v[1] / 100.0 << " * " << v[2] / 100.0 << " * " << v[3] / 100.0 << "\n";
    }
}