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

    int d, na1, na2, nb1, nb2, nc, da, dc;
    cin >> d >> na1 >> na2 >> nb1 >> nb2 >> nc >> da >> dc;

    cout << min({ na1 * na2 / da, nb1 * nb2, nc / dc }) / d;
}