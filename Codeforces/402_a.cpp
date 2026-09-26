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

    int sectorLimit, nutCount, separatorCount, nutLimit;
    cin >> sectorLimit >> nutCount >> separatorCount >> nutLimit;

    int sectorCount = (nutCount + nutLimit - 1) / nutLimit;
    int boxCount = (sectorCount + sectorLimit - 1) / sectorLimit;
    boxCount = max(boxCount, sectorCount - separatorCount);

    cout << boxCount;
}