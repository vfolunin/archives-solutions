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