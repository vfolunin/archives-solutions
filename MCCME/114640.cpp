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

    int aSize;
    cin >> aSize;

    vector<int> aCount(2);
    for (int i = 0; i < aSize; i++) {
        int value;
        cin >> value;

        aCount[value % 2]++;
    }

    int bSize;
    cin >> bSize;

    vector<int> bCount(2);
    for (int i = 0; i < bSize; i++) {
        int value;
        cin >> value;

        bCount[value % 2]++;
    }

    cout << 1LL * aCount[0] * bCount[0] + 1LL * aCount[1] * bCount[1];
}