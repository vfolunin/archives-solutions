#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string cell;
    if (!(cin >> cell))
        return 0;

    long long index = 0;
    for (char c : cell)
        index = index * 26 + c - 'A' + 1;

    if (index <= 16384)
        cout << index << "\n";
    else
        cout << "Essa coluna nao existe Tobias!\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}