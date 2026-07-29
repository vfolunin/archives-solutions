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

    long long workerCount, partCount, partVolume, containerVolume, containerPrice;
    cin >> workerCount >> partCount >> partVolume >> containerVolume >> containerPrice;

    cout << (workerCount * partCount * partVolume + containerVolume - 1) / containerVolume * containerPrice;
}