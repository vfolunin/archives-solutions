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

    double a, b, c;
    cin >> a >> b >> c;

    if (a < b && a < c)
        cout << "Otavio\n";
    else if (b < a && b < c)
        cout << "Bruno\n";
    else if (c < a && c < b)
        cout << "Ian\n";
    else
        cout << "Empate\n";
}