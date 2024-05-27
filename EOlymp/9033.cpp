#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<int, int> count;
    int maxCount = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        for (int delta : { -1, 0, 1 })
            maxCount = max(maxCount, ++count[value + delta]);
    }

    cout << maxCount;
}