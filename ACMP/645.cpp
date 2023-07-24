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

    int n;
    cin >> n;

    int resH = 0, resW = 0;
    for (int h = 1; h <= n; h++) {
        int w = n / h;
        if (h > w)
            break;

        if (!resH || abs(resH - resW) - resH * resW > abs(h - w) - h * w) {
            resH = h;
            resW = w;
        }
    }

    cout << resH << " " << resW;
}