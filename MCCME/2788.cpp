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

    int opCount;
    cin >> opCount;

    set<string> values;

    for (int i = 0; i < opCount; i++) {
        int op;
        string value;
        cin >> op >> value;

        if (op)
            values.insert(value);
        else
            cout << values.count(value) << "\n";
    }
}