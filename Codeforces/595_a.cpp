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

    vector<int> isOn(h * w);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < 2 * w; x++) {
            int value;
            cin >> value;

            isOn[y * w + x / 2] |= value;
        }
    }

    cout << count(isOn.begin(), isOn.end(), 1);
}