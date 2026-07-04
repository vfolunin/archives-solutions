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

    vector<string> a(height);
    for (string &s : a)
        cin >> s;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (a[y][x] == '.')
                continue;

            static vector<int> dy = { 0, 1, 1, 1 };
            static vector<int> dx = { 1, 1, 0, -1 };

            for (int d = 0; d < dy.size(); d++) {
                int step = 0, ok = 1;
                for (; step < 5 && ok; step++) {
                    int ty = y + dy[d] * step;
                    int tx = x + dx[d] * step;
                    ok &= 0 <= ty && ty < height && 0 <= tx && tx < width && a[y][x] == a[ty][tx];
                }

                if (step == 5 && ok) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }

    cout << "No";
}