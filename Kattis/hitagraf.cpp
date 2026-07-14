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

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value >> value >> value;

            static string symbols = "Kk.hH";
            cout << symbols[(value - 1) / 80];
        }
        cout << "\n";
    }
}