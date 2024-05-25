#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    deque<int> values;
    for (string op, type; cin >> op >> type; ) {
        if (op == "push") {
            int value;
            cin >> value;

            if (type == "front")
                values.push_front(value);
            else
                values.push_back(value);
        } else {
            if (type == "front")
                values.pop_front();
            else
                values.pop_back();
        }
    }

    int res = 0;
    for (int value : values)
        if (value % 2)
            res += value;

    cout << res;
}