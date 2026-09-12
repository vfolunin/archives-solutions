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

    int width, pieceCount;
    cin >> width >> pieceCount;

    long long area = 0;
    for (int i = 0; i < pieceCount; i++) {
        int pieceHeight, pieceWidth;
        cin >> pieceHeight >> pieceWidth;
        area += pieceHeight * pieceWidth;
    }

    cout << area / width;
}