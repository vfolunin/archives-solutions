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

    int friendCount, bottleCount, bottleVolume, limeCount, sliceCount, sugarCount, needVolume, needSugar;
    cin >> friendCount >> bottleCount >> bottleVolume >> limeCount >> sliceCount >> sugarCount >> needVolume >> needSugar;

    cout << min({ bottleCount * bottleVolume / needVolume, limeCount * sliceCount, sugarCount / needSugar }) / friendCount;
}