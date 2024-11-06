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

    string s;
    cin >> s;

    int minValue = 1e9, minCount = 0, maxValue = -1e9, maxCount = 0;

    for (int i = 0; i < s.size(); ) {
        if (!isdigit(s[i])) {
            i++;
        } else {
            int value = stoi(s.substr(i + 2, 4));

            if (minValue > value) {
                minValue = value;
                minCount = 1;
            } else if (minValue == value) {
                minCount++;
            }

            if (maxValue < value) {
                maxValue = value;
                maxCount = 1;
            } else if (maxValue == value) {
                maxCount++;
            }

            i += 6;
        }
    }

    cout << minValue << " " << maxValue << "\n" << minCount << " " << maxCount;
}