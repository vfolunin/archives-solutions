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

    int queryCount;
    cin >> queryCount;

    deque<int> values;
    int reversed = 0;

    for (int i = 0; i < queryCount; i++) {
        string type;
        cin >> type;

        if (type == "back") {
            if (values.empty()) {
                cout << "No job for Ada?\n";
            } else if (reversed) {
                cout << values.front() << "\n";
                values.pop_front();
            } else {
                cout << values.back() << "\n";
                values.pop_back();
            }
        } else if (type == "front") {
            if (values.empty()) {
                cout << "No job for Ada?\n";
            } else if (reversed) {
                cout << values.back() << "\n";
                values.pop_back();
            } else {
                cout << values.front() << "\n";
                values.pop_front();
            }
        } else if (type == "reverse") {
            reversed ^= 1;
        } else if (type == "push_back") {
            int value;
            cin >> value;

            if (reversed)
                values.push_front(value);
            else
                values.push_back(value);
        } else {
            int value;
            cin >> value;

            if (reversed)
                values.push_back(value);
            else
                values.push_front(value);
        }
    }
}