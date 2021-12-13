#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double num = 0, den = 0;

    while (1) {
        double w1, w2, r;
        cin >> w1 >> w2 >> r;

        if (!w1 && !w2 && !r)
            break;

        double m = (w1 + w2) / 2 * (1 + r / 30);

        if (m < 13)
            cout << "Nao vai da nao\n";
        else if (m < 14)
            cout << "E 13\n";
        else if (m < 40)
            cout << "Bora, hora do show! BIIR!\n";
        else if (m < 60)
            cout << "Ta saindo da jaula o monstro!\n";
        else
            cout << "AQUI E BODYBUILDER!!\n";

        num += m;
        den++;
    }

    if (num / den > 40)
        cout << "\nAqui nois constroi fibra rapaz! Nao e agua com musculo!\n";
}