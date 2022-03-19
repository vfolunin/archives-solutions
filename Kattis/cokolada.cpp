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

    int pieceCount;
    cin >> pieceCount;

    int size = 0;
    while ((1 << size) < pieceCount)
        size++;

    int bit = 0;
    while (bit <= size && !(pieceCount & (1 << bit)))
        bit++;

    cout << (1 << size) << " " << size - bit;
}