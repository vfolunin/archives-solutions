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

    int setCount;
    cin >> setCount;

    unordered_set<int> values;
    for (int i = 0; i < setCount; i++) {
        int size;
        cin >> size;

        for (int j = 0; j < size; j++) {
            int value;
            cin >> value;

            values.insert(value);
        }
    }

    cout << values.size();
}