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

    int res = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;

            res += value;
        }
    }

    cout << res;
}