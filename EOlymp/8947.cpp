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
        if (y % 2 == 0)
            cout << string(size, '*') << "\n";
        else if (y % 4 == 1)
            cout << string(size - 1, ' ') << "*\n";
        else
            cout << "*" << string(size - 1, ' ') << "\n";
    }
}