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

    int maxValue = 0, sum = 0;
    for (int value; cin >> value; ) {
        if (value % 16 == 9 && value % 25 == 6) {
            maxValue = max(maxValue, value);
            sum += value;
        }
    }

    cout << maxValue << " " << sum;
}