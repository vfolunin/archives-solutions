#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool readStop() {
    int x;
    while (1) {
        cout << "Novo grenal (1-sim 2-nao)\n";
        cin >> x;
        if (1 <= x && x <= 2)
            return x == 2;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int aWins = 0, bWins = 0, draws = 0;

    do {
        int a, b;
        cin >> a >> b;
        aWins += a > b;
        bWins += a < b;
        draws += a == b;
    } while (!readStop());

    cout << aWins + bWins + draws << " grenais\n";
    cout << "Inter:" << aWins << "\n";
    cout << "Gremio:" << bWins << "\n";
    cout << "Empates:" << draws << "\n";
    if (aWins == bWins)
        cout << "Nao houve vencedor\n";
    else
        cout << (aWins > bWins ? "Inter" : "Gremio") << " venceu mais\n";
}