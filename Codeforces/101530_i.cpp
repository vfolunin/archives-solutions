#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("sorting.in", "r", stdin);
    freopen("sorting.out", "w", stdout);

    int size, limit;
    cin >> size >> limit;

    int maxValue = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (maxValue > value && maxValue + value > limit) {
            cout << "No";
            return 0;
        }

        maxValue = max(maxValue, value);
    }

    cout << "Yes";
}