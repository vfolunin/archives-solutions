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

    int bridgeCount, knightCount, groupSize;
    cin >> bridgeCount >> knightCount >> groupSize;

    bridgeCount--;
    int groupCount = knightCount / groupSize;

    cout << (bridgeCount + groupCount - 1) / groupCount;
}