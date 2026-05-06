#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool check(vector<string> &a, char c) {
    bool win = 0, d1 = 1, d2 = 1;

    for (int i = 0; i < a.size(); i++) {
        d1 &= a[i][i] == c;
        d2 &= a[i][a.size() - 1 - i] == c;

        bool h = 1, v = 1;
        for (int j = 0; j < a.size(); j++) {
            h &= a[i][j] == c;
            v &= a[j][i] == c;
        }
        win |= h | v;
    }

    return win || d1 || d2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a(3);
    for (string &s : a)
        cin >> s;

    if (check(a, 'X'))
        cout << "X";
    else if (check(a, 'O'))
        cout << "O";
    else
        cout << "N";
}