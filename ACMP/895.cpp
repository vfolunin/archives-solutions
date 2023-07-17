#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool wins(vector<string> &a, char sign) {
    bool d1 = 1, d2 = 1;
    for (int y = 0; y < a.size(); y++) {
        d1 &= a[y][y] == sign;
        d2 &= a[y][a.size() - 1 - y] == sign;

        bool row = 1, col = 1;
        for (int x = 0; x < a.size(); x++) {
            row &= a[y][x] == sign;
            col &= a[x][y] == sign;
        }
        if (row || col)
            return 1;
    }
    return d1 || d2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> a(3);
    for (string &row : a)
        cin >> row;

    if (wins(a, 'X'))
        cout << "Win";
    else if (wins(a, 'O'))
        cout << "Lose";
    else
        cout << "Draw";
}