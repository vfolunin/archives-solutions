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

    int sum, count, priceA, priceB, priceC;
    cin >> sum >> count >> priceA >> priceB >> priceC;

    for (int countA = 1; countA < count && countA * priceA < sum; countA++) {
        for (int countB = 1; countA + countB < count && countA * priceA + countB * priceB < sum; countB++) {
            int countC = count - countA - countB;
            if (countA * priceA + countB * priceB + countC * priceC == sum) {
                cout << countA << " " << countB << " " << countC;
                return 0;
            }
        }
    }

    cout << "NO SOLUTION";
}