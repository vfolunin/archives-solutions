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

    vector<string> a(3);
    for (string &s : a)
        cin >> s;

    bool win = 0, d1 = 1, d2 = 1;

    for (int i = 0; i < a.size(); i++) {
        d1 &= a[i][i] == 'O';
        d2 &= a[i][a.size() - 1 - i] == 'O';

        bool h = 1, v = 1;
        for (int j = 0; j < a.size(); j++) {
            h &= a[i][j] == 'O';
            v &= a[j][i] == 'O';
        }
        win |= h | v;
    }

    cout << (win || d1 || d2 ? "Jebb" : "Neibb");
}