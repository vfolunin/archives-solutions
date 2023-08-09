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
        int opType;
        cin >> opType;

        if (opType == 1) {
            int value;
            cin >> value;
            values.push_front(value);
        } else if (opType == 2) {
            int value;
            cin >> value;
            values.push_back(value);
        } else if (opType == 3) {
            cout << values.front() << " ";
            values.pop_front();
        } else {
            cout << values.back() << " ";
            values.pop_back();
        }
    }
}