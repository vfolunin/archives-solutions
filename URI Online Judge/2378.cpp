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

    int floorCount, limit;
    cin >> floorCount >> limit;

    int weight = 0, maxWeight = 0;

    for (int i = 0; i < floorCount; i++) {
        int in, out;
        cin >> out >> in;
        weight += in - out;
        maxWeight = max(maxWeight, weight);
    }

    cout << (maxWeight <= limit ? "N\n" : "S\n");
}