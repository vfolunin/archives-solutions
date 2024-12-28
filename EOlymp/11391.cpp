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
            if (x < y)
                cout << "|";
            else if (x == y)
                cout << "@";
            else
                cout << " ";
        }
        for (int x = 1; x < size; x++) {
            if (x + y > size - 1)
                cout << "|";
            else if (x + y == size - 1)
                cout << "@";
            else
                cout << " ";
        }
        cout << "\n";
    }
}