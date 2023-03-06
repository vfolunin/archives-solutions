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

    multiset<int> values;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;
        values.insert(value);

        if (i >= 1)
            cout << *prev(prev(values.end())) << " ";
    }
}