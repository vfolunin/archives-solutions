#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool beats(string &a, string &b) {
    static vector<string> signs = { "pedra", "tesoura", "papel" };
    int sa = find(signs.begin(), signs.end(), a) - signs.begin();
    int sb = find(signs.begin(), signs.end(), b) - signs.begin();
    return (sa + 1) % 3 == sb;
}

bool wins(string &a, string &b, string &c) {
    return beats(a, b) && beats(a, c);
}

bool solve() {
    string a, b, c;
    if (!(cin >> a >> b >> c))
        return 0;

    if (wins(a, b, c))
        cout << "Os atributos dos monstros vao ser inteligencia, sabedoria...\n";
    else if (wins(b, a, c))
        cout << "Iron Maiden's gonna get you, no matter how far!\n";
    else if (wins(c, b, a))
        cout << "Urano perdeu algo muito precioso...\n";
    else
        cout << "Putz vei, o Leo ta demorando muito pra jogar...\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}