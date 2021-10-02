#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double d;
    cin >> d;

    int n = round(d * 100);

    vector<int> nominals = { 10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1 };

    cout.precision(2);
    cout << fixed;

    cout << "NOTAS:\n";
    for (int i = 0; i < 6; i++) {
        cout << n / nominals[i] << " nota(s) de R$ " << nominals[i] / 100.0 << "\n";
        n %= nominals[i];
    }

    cout << "MOEDAS:\n";
    for (int i = 6; i < nominals.size(); i++) {
        cout << n / nominals[i] << " moeda(s) de R$ " << nominals[i] / 100.0 << "\n";
        n %= nominals[i];
    }
}