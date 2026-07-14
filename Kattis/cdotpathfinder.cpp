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

    int h;
    cin >> h;

    for (int y = 0; y < h; y++) {
        int w;
        cin >> w;

        vector<int> num(w), den(w);
        int resX = 0;

        for (int x = 0; x < w; x++) {
            cin >> den[x] >> num[x];

            if (num[resX] * den[x] > num[x] * den[resX])
                resX = x;
        }

        cout << resX + 1 << "\n";
    }
}