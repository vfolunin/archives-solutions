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
    cin >> s >> s;

    int row = 0, res = 0;
    for (char c : s) {
        if (c == 'a') {
            row++;
        } else {
            if (row > 1)
                res += row;
            row = 0;
        }
    }
    if (row > 1)
        res += row;

    cout << res << "\n";
}