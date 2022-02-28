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

    string line;
    cin >> line;

    vector<int> valueCount(3);
    long long inversionCount = 0;

    for (char c : line) {
        for (int i = c - '0' + 1; i < 3; i++)
            inversionCount += valueCount[i];
        valueCount[c - '0']++;
    }

    cout << inversionCount;
}