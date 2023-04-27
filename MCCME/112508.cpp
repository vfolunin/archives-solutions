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

    deque<string> q;
    set<string> values;

    for (string op; cin >> op; ) {
        if (op[0] == '+') {
            string value = op.substr(1);
            if (values.count(value)) {
                cout << "ERROR";
                return 0;
            }
            q.push_front(value);
            values.insert(value);
        } else if (op[0] == '#') {
            string value = op.substr(1);
            if (values.count(value)) {
                cout << "ERROR";
                return 0;
            }
            q.push_back(value);
            values.insert(value);
        } else if (op[0] == '^') {
            if (q.empty()) {
                cout << "ERROR";
                return 0;
            }
            values.erase(q.front());
            q.pop_front();
        } else {
            if (q.empty()) {
                cout << "ERROR";
                return 0;
            }
            values.erase(q.back());
            q.pop_back();
        }
    }

    if (q.empty()) {
        cout << "EMPTY";
    } else {
        for (string &value : q)
            cout << value << " ";
    }
}