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

    char x0, y0;
    cin >> x0 >> y0;
    x0 -= 'a';
    y0 = 7 - (y0 - '1');

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (y == y0 && x == x0)
                cout << "Q ";
            else if (y == y0 || x == x0 || y + x == y0 + x0 || y - x == y0 - x0)
                cout << "* ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}