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

    int planetCount;
    cin >> planetCount;

    map<string, string> planetOf;
    map<string, int> totalCount;

    for (int i = 0; i < planetCount; i++) {
        string planet;
        int speciesCount;
        cin >> planet >> speciesCount;

        totalCount[planet];

        for (int j = 0; j < speciesCount; j++) {
            string species;
            cin >> species;

            planetOf[species] = planet;
        }
    }

    int spacecraftCount;
    cin >> spacecraftCount;

    for (int i = 0; i < spacecraftCount; i++) {
        int count;
        string species;
        cin >> count >> species;

        totalCount[planetOf[species]] += count;
    }

    for (auto &[planet, count] : totalCount)
        cout << planet << " " << count << "\n";
}