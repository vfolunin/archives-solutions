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

    int dayCount;
    double volumeA, volumeB, deltaA, deltaB;
    cin >> dayCount >> volumeA >> volumeB >> deltaA >> deltaB;

    volumeA = max(volumeA - dayCount * deltaA, 0.);
    volumeB = max(volumeB - dayCount * deltaB, 0.);

    cout << fixed << volumeA / (volumeA + volumeB) * 100;
}