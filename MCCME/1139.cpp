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

    int w, h, xCount, yCount;
    cin >> w >> h >> xCount >> yCount;

    vector<int> xs(xCount);
    for (int &x : xs)
        cin >> x;

    vector<int> ys(yCount);
    for (int &y : ys)
        cin >> y;

    int w1 = 0, w2 = 0;
    for (int i = 0; i + 1 < xs.size(); i++) {
        w1 += xs[i + 1] - xs[i] - 1;
        w2 += max(xs[i + 1] - xs[i] - 3, 0);
    }

    int h1 = 0, h2 = 0;
    for (int i = 0; i + 1 < ys.size(); i++) {
        h1 += ys[i + 1] - ys[i] - 1;
        h2 += max(ys[i + 1] - ys[i] - 3, 0);
    }

    cout << h1 * w1 - h2 * w2 << " " << h2 * w2 << " " << h * w - h1 * w1;
}