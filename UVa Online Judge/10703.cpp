#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Rect {
    int x1, y1, x2, y2;

    bool has(int x, int y) {
        return x1 <= x && x <= x2 && y1 <= y && y <= y2;
    }
};

bool solve() {
    int w, h, rectCount;
    cin >> w >> h >> rectCount;

    if (!h && !w && !rectCount)
        return 0;

    vector<Rect> rects(rectCount);
    for (auto &[x1, y1, x2, y2] : rects) {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 > x2)
            swap(x1, x2);
        if (y1 > y2)
            swap(y1, y2);
    }

    int emptyCount = 0;
    for (int x = 1; x <= w; x++) {
        for (int y = 1; y <= h; y++) {        
            bool empty = 0;
            for (Rect &rect : rects)
                empty |= rect.has(x, y);
            emptyCount += !empty;
        }
    }

    if (emptyCount == 0)
        cout << "There is no empty spots.\n";
    else if (emptyCount == 1)
        cout << "There is one empty spot.\n";
    else
        cout << "There are " << emptyCount << " empty spots.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}