#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long double loan, rate, months;
    if (!(cin >> loan >> rate >> months))
        return 0;

    long double simple = loan * (1 + rate * months);
    long double compound = loan * powl(1 + rate, months);

    cout.precision(2);
    cout << "DIFERENCA DE VALOR = " << fixed << fabsl(simple - compound) << "\n";
    cout << "JUROS SIMPLES = " << fixed << simple - loan << "\n";
    cout << "JUROS COMPOSTO = " << fixed << compound - loan << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}