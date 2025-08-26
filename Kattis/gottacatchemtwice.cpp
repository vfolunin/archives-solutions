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

    unordered_set<string> values;
    for (int i = 0; i < size; i++) {
        string value;
        cin >> value;

        values.insert(value);
    }

    cout << values.size() + 1;
}