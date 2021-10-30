#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int d, m;
    if (!(cin >> m >> d))
        return 0;

    static vector<int> days = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    for (int i = 0; i + 1 < m; i++)
        d += days[i];

    if (d == 359)
        cout << "E vespera de natal!\n";
    else if (d == 360)
        cout << "E natal!\n";
    else if (d > 360)
        cout << "Ja passou!\n";
    else
        cout << "Faltam " << 360 - d << " dias para o natal!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}