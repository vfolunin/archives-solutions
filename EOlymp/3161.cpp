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

    vector<deque<int>> a(1.5e5);

    for (int i = 0; i < opCount; i++) {
        string op;
        int index;
        cin >> op >> index;
        index--;

        if (op == "pushfront") {
            int value;
            cin >> value;
            a[index].push_front(value);
        } else if (op == "pushback") {
            int value;
            cin >> value;
            a[index].push_back(value);
        } else if (op == "popfront") {
            cout << a[index].front() << "\n";
            a[index].pop_front();
        } else {
            cout << a[index].back() << "\n";
            a[index].pop_back();
        }
    }
}