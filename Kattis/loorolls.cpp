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

    long long rollSize, pieceSize;
    cin >> rollSize >> pieceSize;

    int res = 1;
    while (rollSize % pieceSize) {
        pieceSize -= rollSize % pieceSize;
        res++;
    }

    cout << res;
}