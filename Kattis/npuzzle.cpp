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

    int res = 0;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            char c;
            cin >> c;

            if (isupper(c)) {
                int ty = (c - 'A') / 4;
                int tx = (c - 'A') % 4;
                res += abs(y - ty) + abs(x - tx);
            }
        }
    }

    cout << res;
}