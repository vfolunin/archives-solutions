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

    deque<int> q;

    char op;
    while (cin >> op) {
        if (op == '+') {
            int value;
            cin >> value;
            q.push_back(value);
        } else if (!q.empty()) {
            q.pop_front();
        } else {
            cout << "ERROR";
            return 0;
        }
    }

    if (!q.empty()) {
        for (int value : q)
            cout << value << " ";
    } else {
        cout << "EMPTY";
    }
}