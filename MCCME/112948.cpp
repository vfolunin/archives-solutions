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

    int h, w, sum;
    cin >> h >> w >> sum;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++)
            cout << (y + x == sum) << " ";
        cout << "\n";
    }
}