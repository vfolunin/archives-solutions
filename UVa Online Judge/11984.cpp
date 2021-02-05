#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double cToF(double t) {
    return t * 9 / 5 + 32;
}

double fToC(double t) {
    return (t - 32) * 5 / 9;
}

void solve(int test) {
    double t, dt;
    cin >> t >> dt;

    t = fToC(cToF(t) + dt);

    cout.precision(2);
    cout << "Case " << test << ": " << fixed << t << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}