#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;

    if (a == b) {
        if (a == "ataque")
            cout << "Aniquilacao mutua\n";
        else if (a == "pedra")
            cout << "Sem ganhador\n";
        else
            cout << "Ambos venceram\n";
    } else {
        if (a == "ataque" || a == "pedra" && b == "papel")
            cout << "Jogador 1 venceu\n";
        else
            cout << "Jogador 2 venceu\n";
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