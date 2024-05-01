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

    int size, targetSum;
    cin >> size >> targetSum;

    unordered_set<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (values.count(targetSum - value)) {
            cout << "YES";
            return 0;
        }

        values.insert(value);
    }

    cout << "NO";
}