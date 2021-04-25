#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve(int test) {
    int h1, s, h2;
    cin >> h1 >> s >> h2;

    int num = s * (h2 - 1);
    int den = (h1 - 1);

    int g = gcd(num, den);
    num /= g;
    den /= g;

    cout << "Case " << test << ": ";
    if (num >= den)
        cout << num / den;
    if (num >= den && num % den)
        cout << " ";
    if (num % den)
        cout << num % den << "/" << den;
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}