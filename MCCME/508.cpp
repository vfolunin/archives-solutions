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

    if (b * 2 < g || g * 2 < b) {
        cout << "NO SOLUTION";
        return 0;
    }

    int d = abs(b - g);
    for (int i = 0; i < d; i++)
        cout << (b < g ? "GBG" : "BGB");
    for (int i = d; i < b && i < g; i++)
        cout << (b < g ? "GB" : "BG");
}