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

    int row = 0, res = 0;
    for (char c : s) {
        if (c == '0')
            row++;
        else
            row = 0;
        res = max(res, row);
    }

    cout << (res + 1) / 2;
}