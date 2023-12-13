#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int size) {
    vector<int> target(size);
    for (int &value : target) {
        cin >> value;

        if (!value)
            return 0;
    }

    vector<int> stack;
    for (int value = 1, i = 0; value <= size; value++) {
        stack.push_back(value);

        while (!stack.empty() && stack.back() == target[i]) {
            stack.pop_back();
            i++;
        }
    }

    cout << (stack.empty() ? "Yes\n" : "No\n");
    return 1;
}

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    while (solve(size));

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}