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

    int h, w, brickCount;
    cin >> h >> w >> brickCount;

    int rowCount = 0, rowLen = 0;
    for (int i = 0; i < brickCount; i++) {
        int brickLen;
        cin >> brickLen;

        rowLen += brickLen;

        if (rowLen > w) {
            cout << "NO";
            return 0;
        }

        if (rowLen == w) {
            rowCount++;
            rowLen = 0;
        }
    }

    cout << (rowCount >= h ? "YES" : "NO");
}