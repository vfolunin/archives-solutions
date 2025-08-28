#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int h, int w) {
    static vector<vector<int>> memo(101, vector<int>(101));
    int &res = memo[h][w];
    if (res)
        return res;

    for (int h1 = 1, h2 = h - 1; h1 <= h2; h1++, h2--)
        if (rec(h1, w) == 2 && rec(h2, w) == 2)
            return res = 1;

    for (int w1 = 1, w2 = w - 1; w1 <= w2; w1++, w2--)
        if (rec(h, w1) == 2 && rec(h, w2) == 2)
            return res = 1;

    return res = 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h, w;
    cin >> h >> w;

    cout << (rec(h, w) == 1 ? "A" : "B");
}