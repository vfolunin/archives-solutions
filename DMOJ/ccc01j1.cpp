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

    for (int stars = 1, spaces = 2 * size - 2; stars <= size; stars += 2, spaces -= 4)
        cout << string(stars, '*') << string(spaces, ' ') << string(stars, '*') << "\n";
    for (int stars = size - 2, spaces = 4; stars >= 1; stars -= 2, spaces += 4)
        cout << string(stars, '*') << string(spaces, ' ') << string(stars, '*') << "\n";
}