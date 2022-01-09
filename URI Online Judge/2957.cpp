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

    int bandCount, limit;
    cin >> bandCount >> limit;
    cin.ignore();

    vector<int> bonuses(128);
    for (int i = 0; i < bandCount; i++) {
        string band;
        getline(cin, band);
        band.erase(remove(band.begin(), band.end(), ' '), band.end());
        int &bonus = bonuses[tolower(band[0])];
        bonus = max<int>(bonus, band.size());
    }

    sort(bonuses.rbegin(), bonuses.rend());
    int totalBonus = 0;
    for (int i = 0; i < bandCount && i < limit; i++)
        totalBonus += bonuses[i];

    cout << totalBonus << "\n";
}