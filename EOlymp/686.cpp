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

    set<int> values;
    int prevRes = 0;

    for (int i = 0; i < opCount; i++) {
        string op;
        int value;
        cin >> op >> value;

        if (op == "+") {
            value = (value + prevRes) % (int)1e9;
            values.insert(value);
            prevRes = 0;
        } else {
            auto it = values.lower_bound(value);
            prevRes = it != values.end() ? *it : -1;
            cout << prevRes << "\n";
        }
    }
}