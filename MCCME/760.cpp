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

    set<int> values;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        values.insert(value);
    }

    for (int value : values)
        cout << value << "\n";
}