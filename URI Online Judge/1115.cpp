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

    while (1) {
        int x, y;
        cin >> x >> y;

        if (x > 0 && y > 0)
            cout << "primeiro\n";
        else if (x < 0 && y > 0)
            cout << "segundo\n";
        else if (x < 0 && y < 0)
            cout << "terceiro\n";
        else if (x > 0 && y < 0)
            cout << "quarto\n";
        else
            break;
    }
}