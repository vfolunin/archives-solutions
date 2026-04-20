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

    int x, y;
    string s;
    cin >> x >> y >> s;

    for (char c : s) {
        x += c == 'R';
        x -= c == 'L';
        y += c == 'U';
        y -= c == 'D';
    }

    cout << x << " " << y;
}