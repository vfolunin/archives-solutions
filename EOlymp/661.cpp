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

    int metalMass, barMass, partMass;
    cin >> metalMass >> barMass >> partMass;

    int res = 0;
    while (1) {
        int barCount = metalMass / barMass;
        int partCount = barMass / partMass * barCount;
        if (!partCount)
            break;

        metalMass -= partCount * partMass;
        res += partCount;
    }

    cout << res;
}