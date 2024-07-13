#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool solve(int test) {
    int period;
    cin >> period;

    if (period < 0)
        return 0;

    string digits;
    cin.ignore(3);
    cin >> digits;

    long long num = stoll(digits), den = 1;
    for (int i = 0; i < digits.size(); i++)
        den *= 10;

    if (period) {
        long long subNum = num, subDen = den;
        for (int i = 0; i < period; i++) {
            subNum /= 10;
            subDen /= 10;
        }
        num -= subNum;
        den -= subDen;
    }

    long long g = gcd(num, den);
    num /= g;
    den /= g;

    cout << "Case " << test << ": " << num << "/" << den << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}