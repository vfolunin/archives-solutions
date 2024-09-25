#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool wins(vector<string> &a, char c) {
    bool d1 = 1, d2 = 1;

    for (int i = 0; i < a.size(); i++) {
        d1 &= a[i][i] == c;
        d2 &= a[i][a.size() - 1 - i] == c;

        bool h = 1, v = 1;
        for (int j = 0; j < a.size(); j++) {
            h &= a[i][j] == c;
            v &= a[j][i] == c;
        }
        if (h || v)
            return 1;
    }

    return d1 || d2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a(3, string(3, ' '));
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            cin >> a[y][x];

    if (wins(a, 'X'))
        cout << "Johan har vunnit";
    else if (wins(a, 'O'))
        cout << "Abdullah har vunnit";
    else
        cout << "ingen har vunnit";
}