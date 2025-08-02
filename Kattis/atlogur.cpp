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

    int size, healthA, damageA;
    cin >> size >> healthA >> damageA;

    int res = 0;
    for (int i = 1; i < size; i++) {
        int healthB, damageB;
        cin >> healthB >> damageB;

        for (int j = 0; healthA > 0 && healthB > 0; j ^= 1) {
            if (j)
                healthA -= damageB;
            else
                healthB -= damageA;
        }

        if (healthB > 0) {
            healthA = healthB;
            damageA = damageB;
            res = i;
        }
    }

    cout << res + 1;
}