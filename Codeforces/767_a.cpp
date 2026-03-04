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
    int from = size;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        values.insert(value);
        while (!values.empty() && *prev(values.end()) == from) {
            cout << from-- << " ";
            values.erase(prev(values.end()));
        }
        cout << "\n";
    }
}