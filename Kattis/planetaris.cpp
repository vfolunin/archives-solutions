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

    int systemCount, shipCount;
    cin >> systemCount >> shipCount;

    vector<int> systems(systemCount);
    for (int &enemyShipCount : systems)
        cin >> enemyShipCount;

    sort(systems.begin(), systems.end());

    int winCount = 0;
    for (int enemyShipCount : systems) {
        if (shipCount > enemyShipCount) {
            shipCount -= enemyShipCount + 1;
            winCount++;
        }
    }

    cout << winCount;
}