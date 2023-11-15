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

    string s;
    cin >> s;

    int curRow = 0, maxRow = 0;
    for (char c : s) {
        if (c == 'k')
            curRow++;
        else
            curRow = 0;
        maxRow = max(maxRow, curRow);
    }

    cout << maxRow;
}