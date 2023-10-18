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

    int size, opCount;
    cin >> size >> opCount;

    multiset<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        values.insert(value);
    }

    for (int i = 0; i < opCount; i++) {
        int value = *values.begin();
        values.erase(values.begin());
        values.insert(value + 1);
    }

    cout << *values.begin();
}