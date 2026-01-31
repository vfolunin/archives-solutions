#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int h, int w, int threshold) {
    if (h > w)
        return rec(w, h, threshold);

    static vector<vector<int>> memo(101, vector<int>(101, -1));
    int &res = memo[h][w];
    if (res != -1)
        return res;

    if (h == 1 && w <= threshold)
        return res = 0;

    set<int> toGrundy;
    for (int h1 = 1, h2 = h - h1; h1 <= h2; h1++, h2--)
        toGrundy.insert(rec(h1, w, threshold) ^ rec(h2, w, threshold));
    for (int w1 = 1, w2 = w - w1; w1 <= w2; w1++, w2--)
        toGrundy.insert(rec(h, w1, threshold) ^ rec(h, w2, threshold));

    res = 0;
    while (toGrundy.count(res))
        res++;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w, threshold;
    cin >> h >> w >> threshold;

    cout << (rec(h, w, threshold) ? 1 : 2);
}