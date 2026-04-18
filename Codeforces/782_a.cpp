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
 
    int size;
    cin >> size;
    size *= 2;

    unordered_set<int> values;
    int res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (values.count(value))
            values.erase(value);
        else
            values.insert(value);

        res = max<int>(res, values.size());
    }

    cout << res;
}