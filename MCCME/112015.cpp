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

    int h, w;
    cin >> h >> w;

    int a = 0, b = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;

            a += c == '.';
            b += c == '*';
        }
    }

    if (a == b)
        cout << 0;
    else if (a < b)
        cout << 1;
    else
        cout << 2;
}