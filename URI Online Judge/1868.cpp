#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void print(int size, int markY, int markX) {
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++)
            cout << (y == markY && x == markX ? "X" : "O");
        cout << "\n";
    }
    cout << "@\n";
}

void line(int size, int y1, int x1, int y2, int x2) {
    while (y1 != y2 || x1 != x2) {
        print(size, y1, x1);
        if (y1 < y2)
            y1++;
        else if (y1 > y2)
            y1--;
        if (x1 < x2)
            x1++;
        else if (x1 > x2)
            x1--;
    }
}

void frame(int size, int frameSize, int y, int x) {
    int off = size / 2 - frameSize / 2;
    line(size, y, x, off, size - 1 - off);
    line(size, off, size - 1 - off, off, off);
    line(size, off, off, size - 1 - off, off);
    line(size, size - 1 - off, off, size - 1 - off, size - 1 - off);
    line(size, size - 1 - off, size - 1 - off, y, x);
}

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    print(size, size / 2, size / 2);
    for (int frameSize = 3, y = size / 2, x = size / 2 + 1; frameSize <= size; frameSize += 2, y++, x++)
        frame(size, frameSize, y, x);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}