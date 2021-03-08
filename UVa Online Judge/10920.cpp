#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long size, n;
    cin >> size >> n;

    if (!size && !n)
        return 0;

    int row = size / 2;
    int col = size / 2;
    n--;

    if (n) {
        n--;
        row++;
    }

    int frameSize = 2;
    for (int frameN = 8; n >= frameN; frameN += 8, frameSize += 2) {
        n -= frameN;
        row++;
        col++;
    }

    static int dRow[] = { 0, -1, 0, 1 };
    static int dCol[] = { -1, 0, 1, 0 };
    
    for (int d = 0; d < 4; d++) {
        int size = (d ? frameSize : frameSize - 1);
        if (n >= size) {
            n -= size;
            col += size * dCol[d];
            row += size * dRow[d];
        } else {
            col += n * dCol[d];
            row += n * dRow[d];
            break;
        }
    }

    cout << "Line = " << row + 1 << ", column = " << col + 1 << ".\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}