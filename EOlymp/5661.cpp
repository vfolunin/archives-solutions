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
            if (y == x)
                cout << (y + 1 < size ? 0 : 100) << " ";
            else
                cout << "1 ";
        }
        cout << "\n";
    }
}