#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    double area;
    cin >> area;

    double radius = sqrt(area / (4 * 3.14));
    double cost = area;

    if (radius < 12) {
        cost *= 0.09;
        cout << "vermelho";
    } else if (radius <= 15) {
        cost *= 0.07;
        cout << "azul";
    } else {
        cost *= 0.05;
        cout << "amarelo";
    }

    cout.precision(2);
    cout << " = R$ " << fixed << cost << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}