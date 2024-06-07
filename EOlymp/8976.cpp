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

    vector<int> a(size);
    unordered_map<int, int> count;
    int maxCount = 0;

    for (int &value : a) {
        cin >> value;
        maxCount = max(maxCount, ++count[value]);
    }

    cout << maxCount << "\n";
    count.clear();
    for (int value : a) {
        if (++count[value] == maxCount)
            cout << value << " ";
    }
}