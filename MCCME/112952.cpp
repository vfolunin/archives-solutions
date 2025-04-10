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
    for (int y = 0; y < size; y++) {
        int prevValue = -1e9;
        for (int x = 0; x < size; x++) {
            int value;
            cin >> value;

            if (prevValue != value)
                count[value]++;

            prevValue = value;
        }
    }

    for (auto &[value, count] : count) {
        if (count == size) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}