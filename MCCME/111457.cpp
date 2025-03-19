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
 
    int size, queryCount;
    cin >> size >> queryCount;

    unordered_set<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);
    }

    int res = 0;
    for (int i = 0; i < queryCount; i++) {
        int value;
        cin >> value;

        res += values.count(value);
    }

    cout << res;
}