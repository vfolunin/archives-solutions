#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int abilityCount, jobCount;
    cin >> abilityCount >> jobCount;

    unordered_set<string> abilities;
    for (int i = 0; i < abilityCount; i++) {
        string ability;
        cin >> ability;

        abilities.insert(ability);
    }

    for (int i = 0; i < jobCount; i++) {
        int needCount, ok = 1;
        cin >> needCount;

        for (int j = 0; j < needCount; j++) {
            string need;
            cin >> need;

            ok &= abilities.contains(need);
        }

        cout << (ok ? "apply\n" : "why bother?\n");
    }
}