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

    int size;
    cin >> size;

    map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        count[value]++;
    }

    int targetCount;
    cin >> targetCount;

    bool found = 0;
    for (auto [value, count] : count) {
        if (count == targetCount) {
            found = 1;
            cout << value << " ";
        }
    }

    if (!found)
        cout << 0;
}