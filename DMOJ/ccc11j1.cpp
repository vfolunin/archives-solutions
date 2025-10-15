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

    int a, b;
    cin >> a >> b;

    if (a >= 3 && b <= 4)
        cout << "TroyMartian\n";
    if (a <= 6 && b >= 2)
        cout << "VladSaturnian\n";
    if (a <= 2 && b <= 3)
        cout << "GraemeMercurian\n";
}