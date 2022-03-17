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

    int costumeCount;
    cin >> costumeCount;

    map<string, int> costumeFrequency;
    for (int i = 0; i < costumeCount; i++) {
        string costume;
        cin >> costume;
        costumeFrequency[costume]++;
    }

    int minFrequency = costumeCount;
    for (auto &[costume, frequency] : costumeFrequency)
        minFrequency = min(minFrequency, frequency);

    set<string> winnerCostumes;
    for (auto &[costume, frequency] : costumeFrequency)
        if (frequency == minFrequency)
            winnerCostumes.insert(costume);

    for (const string &costume : winnerCostumes)
        cout << costume << "\n";
}