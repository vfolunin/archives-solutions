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

    int rectangleCount;
    cin >> rectangleCount;

    vector<pair<long long, long long>> rectangles(rectangleCount);
    for (auto &[h, w] : rectangles) {
        cin >> h >> w;
        if (h > w)
            swap(h, w);
    }

    sort(rectangles.begin(), rectangles.end(), [](auto &a, auto &b) {
        if (a.first != b.first)
            return a.first > b.first;
        return a.second < b.second;
    });

    auto [h, w] = rectangles[0];
    long long res = h * w;

    for (auto &[curH, curW] : rectangles) {
        if (w < curW) {
            res += curH * (curW - w);
            h = curH;
            w = curW;
        }
    }

    cout << res;
}