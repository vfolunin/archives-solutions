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

    int size;
    cin >> size;

    vector<int> stack;
    int stackValue = 1;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        while ((stack.empty() || stack.back() != value) && stackValue <= size) {
            stack.push_back(stackValue);
            stackValue++;
        }

        if (!stack.empty() && stack.back() == value) {
            stack.pop_back();
        } else {
            cout << "Cheater";
            return 0;
        }
    }

    cout << "Not a proof";
}