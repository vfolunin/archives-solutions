#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Box {
    int x1, x2, y1, y2, z1, z2;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<Box> boxes(n);
    for (auto &[x1, x2, y1, y2, z1, z2] : boxes)
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

    int res = 0;

    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            for (int z = 0; z <= 100; z++) {
                for (auto &[x1, x2, y1, y2, z1, z2] : boxes) {
                    if (x1 <= x && x < x2 && y1 <= y && y < y2 && z1 <= z && z < z2) {
                        res++;
                        break;
                    }
                }
            }
        }
    }

    cout << res;
}