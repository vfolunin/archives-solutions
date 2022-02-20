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

    int brickCount;
    cin >> brickCount;

    int towerCount = 1, lastBrick = 1e9;
    for (int i = 0; i < brickCount; i++) {
        int brick;
        cin >> brick;

        if (brick > lastBrick)
            towerCount++;
        lastBrick = brick;
    }

    cout << towerCount;
}