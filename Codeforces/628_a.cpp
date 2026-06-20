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

    int playerCount, bottleCount, towelCount;
    cin >> playerCount >> bottleCount >> towelCount;

    cout << (playerCount - 1) * (2 * bottleCount + 1) << " " << playerCount * towelCount;
}