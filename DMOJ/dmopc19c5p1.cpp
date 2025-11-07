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

    unordered_set<string> values;
    for (int i = 0; i < size; i++) {
        string value;
        cin >> value;

        values.insert(value);
    }

    int res = 0;
    for (int i = 0; i < queryCount; i++) {
        int size;
        cin >> size;

        int ok = 1;
        for (int j = 0; j < size; j++) {
            string value;
            cin >> value;

            ok &= values.count(value);
        }

        res += ok;
    }

    cout << res;
}