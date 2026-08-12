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

    int priceA, capacityA, priceB, capacityB, sum;
    cin >> priceA >> capacityA >> priceB >> capacityB >> sum;

    int resA, resB, resCost = 1e9;
    for (int countA = 0, countB = sum; countA <= sum; countA++, countB--) {
        int tripsA = (countA + capacityA - 1) / capacityA;
        int tripsB = (countB + capacityB - 1) / capacityB;
        int cost =  tripsA * priceA + tripsB * priceB;

        if (resCost > cost) {
            resA = tripsA;
            resB = tripsB;
            resCost = cost;
        }
    }

    cout << resA << " " << resB << " " << resCost;
}