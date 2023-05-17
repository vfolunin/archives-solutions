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

    double a, b;
    int n;
    cin >> a >> b >> n;
    long long num = a * 1e5, den = b * 1e5;

    vector<long long> digits(n + 2);
    for (int i = 0; i < digits.size(); i++) {
        digits[i] = num / den;
        num = (num - digits[i] * den) * 10;
    }
    digits[n] += digits[n + 1] >= 5;

    cout << digits[0];
    if (n)
        cout << ",";
    for (int i = 1; i <= n; i++)
        cout << digits[i];
}