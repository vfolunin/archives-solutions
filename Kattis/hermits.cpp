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

    int streetCount;
    cin >> streetCount;

    vector<int> population(streetCount);
    for (int &value : population)
        cin >> value;

    int streetPairCount;
    cin >> streetPairCount;

    vector<int> totalPopulation = population;
    for (int i = 0; i < streetPairCount; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        totalPopulation[a] += population[b];
        totalPopulation[b] += population[a];
    }

    cout << min_element(totalPopulation.begin(), totalPopulation.end()) - totalPopulation.begin() + 1;
}