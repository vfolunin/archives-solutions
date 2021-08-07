#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<unsigned long long> sums(1500);
    for (unsigned long long &sum : sums)
        cin >> sum;

    unsigned long long x = sums[1000];
    vector<unsigned long long> coeffs(7);
    for (unsigned long long &coeff : coeffs) {
        coeff = (x % 1001 + 1001) % 1001;
        x = (x - coeff) / 1001;
    }

    bool ok = 1;
    for (int i = 0; ok && i < 1500; i++) {
        unsigned long long sum = 0, power = 1;
        for (int p = 0; p < 7; p++, power *= i + 1)
            sum += coeffs[p] * power;
        ok &= sum == sums[i];
    }

    if (ok) {
        for (int i = 0; i < coeffs.size(); i++)
            cout << coeffs[i] << (i + 1 < coeffs.size() ? " " : "\n");
    } else {
        cout << "This is a smart sequence!\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}