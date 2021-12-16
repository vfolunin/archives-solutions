#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    double a, b;
    if (!(cin >> a >> b))
        return 0;

    cout << "Projeto " << test << ":\n";
    cout << "Percentual dos juros da aplicacao: ";
    cout.precision(2);
    cout << fixed << (b - a) / a * 100 << " %\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}