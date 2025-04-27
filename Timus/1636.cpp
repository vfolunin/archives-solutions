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

    int penaltyA, penaltyB;
    cin >> penaltyA >> penaltyB;

    for (int i = 0; i < 10; i++) {
        int tries;
        cin >> tries;

        if (tries)
            penaltyB -= tries * 20;
    }

    cout << (penaltyA > penaltyB ? "Dirty debug :(" : "No chance.");
}