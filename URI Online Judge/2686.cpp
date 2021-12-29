#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double angle;
    if (!(cin >> angle))
        return 0;

    int t = ((int)round(angle / 360 * 24 * 3600) + 6 * 3600) % (24 * 3600);
    int h = t / 3600;
    int m = t % 3600 / 60;
    int s = t % 60;

    if (angle == 360 || angle < 90)
        cout << "Bom Dia!!\n";
    else if (angle < 180)
        cout << "Boa Tarde!!\n";
    else if (angle < 270)
        cout << "Boa Noite!!\n";
    else
        cout << "De Madrugada!!\n";

    cout << setw(2) << setfill('0') << h << ":";
    cout << setw(2) << setfill('0') << m << ":";
    cout << setw(2) << setfill('0') << s << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}