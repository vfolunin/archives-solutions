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

    long long height, width, perimeterLimit;
    cin >> height >> width >> perimeterLimit;

    long long res = 0;
    for (long long h = 1; h <= height && h * 2 < perimeterLimit; h++) {
        long long wMax = min(width, perimeterLimit / 2 - h);
        long long wSum = wMax * (width + 1) - wMax * (wMax + 1) / 2;
        res += (height - h + 1) * wSum;
    }

    cout << res;
}