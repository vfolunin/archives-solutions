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

    int opCount;
    cin >> opCount;

    deque<int> values;
    for (int i = 0; i < opCount; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            cin >> values.emplace_front();
        } else if (op == 2) {
            cin >> values.emplace_back();
        } else if (op == 3) {
            cout << values.front() << "\n";
            values.pop_front();
        } else {
            cout << values.back() << "\n";
            values.pop_back();
        }
    }
}