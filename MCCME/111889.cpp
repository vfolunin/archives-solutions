#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getRectCount(int totalSize, int rectSize) {
    totalSize -= rectSize - 1;
    int count = (totalSize + rectSize - 1) / rectSize;
    return (count + 1) / 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int totalH, totalW, rectH, rectW;
    cin >> totalH >> totalW >> rectH >> rectW;

    cout << getRectCount(totalH, rectH) * getRectCount(totalW, rectW);
}