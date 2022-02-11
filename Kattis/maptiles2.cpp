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

    int x = 0, y = 0, half = (1 << (s.size() - 1));
    for (char c : s) {
        if (c == '1' || c == '3')
            x += half;
        if (c == '2' || c == '3')
            y += half;
        half /= 2;
    }

    cout << s.size() << " " << x << " " << y;
}