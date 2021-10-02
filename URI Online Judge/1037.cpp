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

    double x;
    cin >> x;

    if (x < 0 || x > 100) {
        cout << "Fora de intervalo\n";
    } else {
        int l = 0;
        while (l + 25 < x)
            l += 25;

        cout << "Intervalo " << (l ? "(" : "[") << l << "," << l + 25 << "]\n";
    }
}