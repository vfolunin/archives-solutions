#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    double num = 0, den = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            num += gcd(a[i], a[j]) == 1;
            den++;
        }
    }

    if (num)
        cout << fixed << sqrt(6.0 / (num / den)) << "\n";
    else
        cout << "No estimate for this data set.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}