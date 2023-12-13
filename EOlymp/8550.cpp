#include <iostream>
#include <iomanip>
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

    for (int y = 0, even = 1, odd = (size * size + 1) / 2 + 1; y < size; y++)
        for (int x = 0; x < size; x++)
            cout << setw(2) << ((y + x) % 2 ? odd++ : even++) << (x + 1 < size ? ' ' : '\n');
}