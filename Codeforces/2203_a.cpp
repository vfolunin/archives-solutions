#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int boxCount, weight, durability;
    cin >> boxCount >> weight >> durability;

    int towerSize = 1 + durability / weight;

    cout << (boxCount + towerSize - 1) / towerSize << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}