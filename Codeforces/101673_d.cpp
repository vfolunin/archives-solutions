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

    int peopleCount, opCount;
    cin >> peopleCount >> opCount;

    vector<int> stack = { 0 };

    for (int i = 0; i < opCount; i++) {
        string op;
        cin >> op;

        if (op == "undo") {
            cin >> op;
            int n = stoi(op);
            for (int j = 0; j < n; j++)
                stack.pop_back();
        } else {
            stack.push_back((stack.back() + stoi(op) % peopleCount + peopleCount) % peopleCount);
        }
    }

    cout << stack.back();
}