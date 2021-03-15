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

    return { mantissa, exponent };
}

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    static auto [mantissa, exponent] = prepare();

    cout << "2^-" << n << " = ";
    cout.precision(3);
    cout << fixed << mantissa[n] << "e-" << exponent[n] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}