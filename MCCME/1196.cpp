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

    int y = 3, x = 0, res = 0;
    for (char c : s) {
        int ny = 3, nx = 1;
        if (c != '0') {
            ny = (c - '1') / 3;
            nx = (c - '1') % 3;
        }
        
        res += abs(y - ny) + abs(x - nx) + 1;

        y = ny;
        x = nx;
    }

    res += abs(y - 3) + abs(x - 2) + 1;

    cout << res;
}