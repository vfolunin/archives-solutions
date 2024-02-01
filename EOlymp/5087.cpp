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

    int opCount;
    cin >> opCount;

    vector<int> stack;
    for (int i = 0; i < opCount; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int value;
            cin >> value;
            stack.push_back(value);
        } else {
            cout << stack.back() << "\n";
            stack.pop_back();
        }
    }
}