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

    vector<int> squads(3);
    for (int &value : squads)
        cin >> value;

    vector<int> soldiers(3);
    for (int &value : soldiers)
        cin >> value;

    int maxPower = 0;
    for (int i = 0; i < squads.size(); i++)
        maxPower = max(maxPower, squads[i] * soldiers[i]);

    vector<string> names = { "Conrad", "Harold", "Wilhelm" };

    for (int i = 0; i < squads.size(); i++)
        if (maxPower == squads[i] * soldiers[i])
            cout << names[i] << " ";
}