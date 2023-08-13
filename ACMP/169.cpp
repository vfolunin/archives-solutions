#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int dist, stepCount;
    cin >> dist >> stepCount;

    vector<unordered_map<int, int>> ways(stepCount);
    ways[0][0] = 1;

    for (int steps = 1; steps < stepCount; steps++)
        for (int pos = -steps; pos < dist; pos++)
            ways[steps][pos] = ways[steps - 1][pos - 1] + ways[steps - 1][pos + 1];

    cout << ways[stepCount - 1][dist - 1];
}