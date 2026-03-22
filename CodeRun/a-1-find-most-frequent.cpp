#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    int size;
    cin >> size;

    map<int, int> count;
    int maxCount = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        maxCount = max(maxCount, ++count[value]);
    }

    int res;
    for (auto &[value, count] : count)
        if (count == maxCount)
            res = value;

    cout << res;
}