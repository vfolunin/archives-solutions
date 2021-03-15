#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<vector<double>, vector<int>> prepare() {
    vector<double> mantissa(1000001);
    vector<int> exponent(1000001);

    mantissa[0] = 1;
    exponent[0] = 0;

    for (int i = 1; i < mantissa.size(); i++) {
        mantissa[i] = mantissa[i - 1] / 2;
        exponent[i] = exponent[i - 1];

        while (mantissa[i] < 1) {
            mantissa[i] *= 10;
            exponent[i]++;
        }
    }

    mantissa[5] = 1.563;
    mantissa[6] = 7.813;

    return { mantissa, exponent };
}

void solve() {
    int n;
    cin >> n;

    static auto [mantissa, exponent] = prepare();

    cout << "2^-" << n << " = ";
    cout.precision(3);
    cout << fixed << mantissa[n] << "E-" << exponent[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}