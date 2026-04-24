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

    int height, width;
    cin >> height >> width;

    int res = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char c;
            cin >> c;

            res += c == 'x';
        }
    }

    cout << res;
}