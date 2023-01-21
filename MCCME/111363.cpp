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
        for (int x = 0; x < size; x++) {
            if (y == size / 2 || x == size / 2 || y == x || y + x == size - 1)
                cout << "* ";
            else
                cout << ". ";
        }
        cout << "\n";
    }
}