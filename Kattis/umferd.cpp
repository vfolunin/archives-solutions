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

    int w, h;
    cin >> w >> h;

    double count = 0;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            char c;
            cin >> c;
            count += c == '.';
        }
    }

    cout << fixed << count / (h * w);
}