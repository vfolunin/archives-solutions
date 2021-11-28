#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <complex>
using namespace std;

void solve() {
    long long re, im;
    cin >> re >> im;

    complex<long long> c(re, im), p = c;
    int res = 1;

    while (p.real() <= 1LL << 30 && p.imag()) {
        p *= c;
        res++;
    }

    if (p.imag())
        cout << "TOO COMPLICATED\n";
    else
        cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}