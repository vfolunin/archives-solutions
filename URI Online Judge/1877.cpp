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

    int towerCount, targetPeakCount;
    cin >> towerCount >> targetPeakCount;

    vector<int> towers(towerCount);
    for (int &tower : towers)
        cin >> tower;

    int peakCount = 0;
    for (int i = 1; i + 1 < towerCount; i++)
        peakCount += towers[i - 1] < towers[i] && towers[i] > towers[i + 1];

    if (peakCount == targetPeakCount)
        cout << "beautiful\n";
    else
        cout << "ugly\n";
}