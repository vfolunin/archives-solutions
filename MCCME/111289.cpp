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

    int sum;
    cin >> sum;

    int resCount2 = 100, resCount3 = 100;
    for (int count2 = 0; count2 * 2 <= sum; count2++) {
        int count3 = (sum - count2 * 2) / 3;
        if (count2 * 2 + count3 * 3 == sum && resCount2 + resCount3 > count2 + count3) {
            resCount2 = count2;
            resCount3 = count3;
        }
    }

    cout << resCount2 << " " << resCount3;
}