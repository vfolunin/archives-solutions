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
        if (c == '5') {
            row++;
        } else {
            while (row > 3) {
                row -= 3;
                res++;
            }
            row = 0;
        }
    }
    while (row > 3) {
        row -= 3;
        res++;
    }

    cout << res;
}