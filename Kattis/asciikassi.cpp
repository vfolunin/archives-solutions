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

    size += 2;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if ((y == 0 || y == size - 1) && (x == 0 || x == size - 1))
                cout << "+";
            else if (y == 0 || y == size - 1)
                cout << "-";
            else if (x == 0 || x == size - 1)
                cout << "|";
            else
                cout << " ";
        }
        cout << "\n";
    }
}