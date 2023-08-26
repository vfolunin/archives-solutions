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

    int logSize, logsNeeded, treeSize;
    cin >> logSize >> logsNeeded >> treeSize;

    int logsPerTree = treeSize / logSize;

    cout << (logsNeeded + logsPerTree - 1) / logsPerTree;
}