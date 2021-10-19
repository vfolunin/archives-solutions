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

    int dist, tollDist, kmCost, tollCost;
    cin >> dist >> tollDist >> kmCost >> tollCost;

    cout << dist * kmCost + dist / tollDist * tollCost << "\n";
}