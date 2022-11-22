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

    vector<int> maxValue(2);

    for (int i = 0; i < 30; i++) {
        int value;
        cin >> value;

        maxValue[value % 2] = max(maxValue[value % 2], value);
    }

    cout << maxValue[0] - maxValue[1];
}