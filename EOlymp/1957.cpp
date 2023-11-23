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

    set<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        values.insert(value);
    }

    values.erase(prev(values.end()));

    cout << *prev(values.end());
}