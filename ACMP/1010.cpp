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

    if (size == 1) {
        cout << "A";
        return 0;
    }

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << (char)(x + 'A');
        cout << " ";
    }
    cout << "\n";

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << (char)(y + 'A');
        cout << " ";
    }
    cout << "\n";

    for (int z = 2; z < size; z++) {
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++)
                cout << "A";
            cout << " ";
        }
        cout << "\n";
    }
}