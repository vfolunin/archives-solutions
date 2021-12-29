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

    long double v;
    cin >> v;

    long double c = 3e8, lambda0 = 700, EPS = 1e-9;
    long double lambda = sqrt((c - v) / (c + v)) * lambda0;

    if (lambda + EPS < 400)
        cout << "invisivel\n";
    else if (lambda + EPS < 425)
        cout << "violeta\n";
    else if (lambda + EPS < 445)
        cout << "anil\n";
    else if (lambda + EPS < 500)
        cout << "azul\n";
    else if (lambda + EPS < 575)
        cout << "verde\n";
    else if (lambda + EPS < 585)
        cout << "amarelo\n";
    else if (lambda + EPS < 620)
        cout << "laranja\n";
    else if (lambda + EPS < 750)
        cout << "vermelho\n";
    else
        cout << "invisivel\n";
}