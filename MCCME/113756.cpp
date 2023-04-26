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

    int depthLimit, initialCost, extraCost, depth, failCost, targetDepth;
    cin >> depthLimit >> initialCost >> extraCost >> depth >> failCost >> targetDepth;

    int verdict = depth >= targetDepth;
    if (verdict)
        depth = targetDepth;

    cout << verdict << " " << (verdict ? initialCost + max(0, depth - depthLimit) * extraCost : depth * failCost);
}