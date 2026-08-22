#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("table.in", "r", stdin);
    freopen("table.out", "w", stdout);

    int b, g;
    cin >> b >> g;

    while (b || g) {
        if (b) {
            cout << "B";
            b--;
        }
        if (g) {
            cout << "G";
            g--;
        }
        if (g) {
            cout << "G";
            g--;
        }
    }
}