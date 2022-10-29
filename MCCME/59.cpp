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

    string op;
    while (cin >> op) {
        if (op == "push") {
            int value;
            cin >> value;
            cout << "ok\n";
            q.push_back(value);
        } else if (op == "pop") {
            if (q.empty()) {
                cout << "error\n";
            } else {
                cout << q.front() << "\n";
                q.pop_front();
            }
        } else if (op == "front") {
            if (q.empty())
                cout << "error\n";
            else
                cout << q.front() << "\n";
        } else if (op == "size") {
            cout << q.size() << "\n";
        } else if (op == "clear") {
            cout << "ok\n";
            q.clear();
        } else {
            cout << "bye\n";
            break;
        }
    }
}