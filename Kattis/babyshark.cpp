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

    string prevS, maxS;
    int row, maxRow = 0;

    for (string s; cin >> s; ) {
        if (prevS == s)
            row++;
        else
            row = 1;

        if (maxRow < row) {
            maxS = s;
            maxRow = row;
        }

        prevS = s;
    }

    cout << maxS;
}