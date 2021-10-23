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

    int divisionCount;
    cin >> divisionCount;

    int storedPieceCount = 0;
    for (int i = 0; i < divisionCount; i++) {
        int pieceCount;
        cin >> pieceCount;
        storedPieceCount += pieceCount - 1;
    }

    cout << storedPieceCount << "\n";
}