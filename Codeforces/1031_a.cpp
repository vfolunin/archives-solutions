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

    int height, width, ringCount;
    cin >> height >> width >> ringCount;

    int cellCount = 0;
    for (int i = 0; i < ringCount && height > 0 && width > 0; i++) {
        if (height == 1 || width == 1)
            cellCount += height == 1 ? width : height;
        else
            cellCount += 2 * height + 2 * width - 4;
        height -= 4;
        width -= 4;
    }

    cout << cellCount;
}