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

    for (int y = 0; y < size * 2 - 1; y++) {
        for (int x = 0; x < size * 2 - 1; x++)
            cout << (char)(size - 1 - min({ y, size * 2 - 2 - y, x, size * 2 - 2 - x }) + 'a');
        cout << "\n";
    }
}