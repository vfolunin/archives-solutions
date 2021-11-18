#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    if (!(cin >> n))
        return 0;

    if (n == 360 || n < 90)
        cout << "Bom Dia!!\n";
    else if (n < 180)
        cout << "Boa Tarde!!\n";
    else if (n < 270)
        cout << "Boa Noite!!\n";
    else
        cout << "De Madrugada!!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}