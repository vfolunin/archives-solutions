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

    int size;
    cin >> size;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < 2 * size - 1; x++)
            cout << ((y == 0 || y == size - 1) && x % 2 == 0 ||
                     (x == 0 || x == 2 * size - 2) ? "*" : " ");
        cout << "\n";
    }
}