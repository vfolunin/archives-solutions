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

    int creatureCount, legCount;
    cin >> creatureCount >> legCount;

    for (int sheepCount = 0; sheepCount <= creatureCount; sheepCount++) {
        if (sheepCount * 4 + (creatureCount - sheepCount) * 2 == legCount) {
            cout << sheepCount;
            return 0;
        }
    }

    cout << "Rong talning";
}