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

    const long long S = 2000;
    const long long P = 2e9;
    const long long M = 1e6;
    cout.precision(2);
    cout << fixed;

    for (long long a = 1; a + a + a + a <= S && a * a * a * a <= P; a++) {
        for (long long b = a; a + b + b + b <= S && a * b * b * b <= P; b++) {
            for (long long c = b; a + b + c + c <= S && a * b * c * c <= P; c++) {
                if (a * b * c == M)
                    continue;

                long long d = (a + b + c) * M / (a * b * c - M);

                if (c <= d && a + b + c + d <= S && a * b * c * d <= P && (a + b + c + d) * M == a * b * c * d)
                    cout << a / 100.0 << " " << b / 100.0 << " " << c / 100.0 << " " << d / 100.0 << "\n";
            }
        }
    }
}