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
            if (y % 2 == 0)
                cout << y * size + x + 1 << " ";
            else
                cout << (y + 1) * size - x << " ";
        }
        cout << "\n";
    }
}