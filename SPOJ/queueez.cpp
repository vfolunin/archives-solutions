#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int queryCount;
    cin >> queryCount;

    queue<int> values;
    for (int i = 0; i < queryCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int value;
            cin >> value;

            values.push(value);
        } else if (type == 2) {
            if (!values.empty())
                values.pop();
        } else {
            if (values.empty())
                cout << "Empty!\n";
            else
                cout << values.front() << "\n";
        }
    }
}