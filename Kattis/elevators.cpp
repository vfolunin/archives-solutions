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

    string type;
    int floorCount;
    cin >> type >> floorCount;

    unordered_map<string, vector<int>> elevatorCount = {
        { "residential", { 2, 6, 11, 16, 21 } },
        { "commercial", { 2, 8, 15, 21 } },
        { "industrial", { 2, 5, 9, 13, 17, 21 } }
    };

    vector<int> &count = elevatorCount[type];

    cout << upper_bound(count.begin(), count.end(), floorCount) - count.begin();
}