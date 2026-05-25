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

    long long countA, hpA, dmgA, countB, hpB, dmgB;
    cin >> countA >> hpA >> dmgA >> countB >> hpB >> dmgB;

    long long totalHpA = countA * hpA;
    long long totalHpB = countB * hpB;

    while (1) {
        long long totalDmgB = (totalHpB + hpB - 1) / hpB * dmgB;
        totalHpA = max(totalHpA - totalDmgB, 0LL);
        if (!totalHpA)
            break;

        long long totalDmgA = (totalHpA + hpA - 1) / hpA * dmgA;
        totalHpB = max(totalHpB - totalDmgA, 0LL);
        if (!totalHpB)
            break;
    }

    cout << (totalHpA ? "Good" : "Evil");
}