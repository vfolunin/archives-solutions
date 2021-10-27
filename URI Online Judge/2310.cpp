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

    int playerCount;
    cin >> playerCount;

    vector<int> num(3), den(3);

    for (int i = 0; i < playerCount; i++) {
        string name;
        cin >> name;

        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            den[j] += x;
        }
        
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            num[j] += x;
        }
    }

    vector<string> type = { "Saque", "Bloqueio", "Ataque" };
    cout.precision(2);
    cout << fixed;
    for (int i = 0; i < 3; i++)
        cout << "Pontos de " << type[i] << ": " << 100.0 * num[i] / den[i] << " %.\n";
}