#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetDiff;
    cin >> size >> targetDiff;

    unordered_set<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);

        if (values.count(value - targetDiff) || values.count(value + targetDiff)) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
}