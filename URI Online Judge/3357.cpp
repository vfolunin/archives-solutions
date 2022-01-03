#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int peopleCount;
    double totalVolume, cupVolume;
    cin >> peopleCount >> totalVolume >> cupVolume;

    vector<string> names(peopleCount);
    for (string &name : names)
        cin >> name;

    int cupCount = ceil(totalVolume / cupVolume);
    double lastVolume = fmod(totalVolume, cupVolume);
    if (lastVolume < 1e-9)
        lastVolume = cupVolume;

    cout << names[(cupCount - 1) % peopleCount] << " ";
    cout.precision(1);
    cout << fixed << lastVolume << "\n";
}