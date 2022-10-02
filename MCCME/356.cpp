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

    vector<int> sums(h);
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;
            sums[y] += value;
        }
    }

    int maxIndex = max_element(sums.begin(), sums.end()) - sums.begin();

    cout << sums[maxIndex] << "\n" << maxIndex;
}