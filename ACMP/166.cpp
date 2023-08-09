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

    vector<long long> robots(4);
    int time;
    cin >> robots[3] >> time;

    for (int i = 1; i < time; i++) {
        rotate(robots.begin(), robots.begin() + 1, robots.end());
        robots[3] = 0;
        
        long long curRobots = robots[0] + robots[1] + robots[2];
        for (long long k3 = 0, k5 = curRobots; k3 <= curRobots && k3 < 100; k3++, k5--)
            robots[3] = max(robots[3], k3 / 3 * 5 + k5 / 5 * 9);
    }

    cout << robots[1] + robots[2] + robots[3];
}