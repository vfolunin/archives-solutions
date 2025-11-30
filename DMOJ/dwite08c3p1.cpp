#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    for (int dots = (size - 1) / 2, hashes = 1; hashes <= size; dots--, hashes += 2)
        cout << string(dots, '.') << string(hashes, '#') << string(dots, '.') << "\n";
    for (int dots = 1, hashes = size - 2; hashes > 0; dots++, hashes -= 2)
        cout << string(dots, '.') << string(hashes, '#') << string(dots, '.') << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}