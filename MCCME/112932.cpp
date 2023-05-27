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

    for (int y = 0, pos = -1; y < size; y++, pos += y % 2 ? 0 : 2) {
        for (int x = 0; x < size; x++) {
            if (y % 2 == 0)
                cout << (pos <= x && x <= pos + 2) << " ";
            else
                cout << (x == pos + 2) << " ";
        }
        cout << "\n";
    }
}