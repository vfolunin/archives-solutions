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

    int obstacleCount, foundObstacleCount;
    cin >> obstacleCount >> foundObstacleCount;

    set<int> foundObstacles;
    for (int i = 0; i < foundObstacleCount; i++) {
        int x;
        cin >> x;
        foundObstacles.insert(x);
    }

    for (int x = 0; x < obstacleCount; x++)
        if (!foundObstacles.count(x))
            cout << x << "\n";

    cout << "Mario got " << foundObstacles.size() << " of the dangerous obstacles.";
}