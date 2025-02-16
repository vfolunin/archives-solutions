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

    for (int y = 0; y < size / 2; y++) {
        for (int x = 0; x < size / 2; x++)
            cout << (y + x == size / 2 ? "*" : " ");
        cout << "*";
        for (int x = 0; x < size / 2; x++)
            cout << (y - 1 == x ? "*" : " ");
        cout << "\n";
    }
    cout << string(size, '*') << "\n";
    for (int y = 0; y < size / 2; y++) {
        for (int x = 0; x < size / 2; x++)
            cout << (y == x - 1 ? "*" : " ");
        cout << "*";
        for (int x = 0; x < size / 2; x++)
            cout << (y + x == size / 2 - 2 ? "*" : " ");
        cout << "\n";
    }
}