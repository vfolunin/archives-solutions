#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetSize;
    cin >> size >> targetSize;

    unordered_set<int> pieces;
    for (int i = 0; i < size; i++) {
        int pieceCount;
        cin >> pieceCount;

        for (int j = 0; j < pieceCount; j++) {
            int piece;
            cin >> piece;

            pieces.insert(piece);
        }
    }

    cout << (pieces.size() == targetSize ? "Jebb" : "Neibb");
}