#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, height, width;
    cin >> size >> height >> width;

    if (height > width)
        swap(height, width);

    int yCount = 0, xCount = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        yCount += value <= height;
        xCount += height < value && value <= width;
    }

    int res = 0;
    
    int delta = min(yCount, xCount);
    res += delta;
    yCount -= delta;
    xCount -= delta;

    res += yCount / 2;

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}