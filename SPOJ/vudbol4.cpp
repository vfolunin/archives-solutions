#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    for (int y = 0; y < 2 * size; y++) {
        for (int x = 0; x < 2 * size; x++)
            cout << a[y / 2][x / 2];
        cout << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}