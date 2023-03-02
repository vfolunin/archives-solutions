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

    vector<pair<int, int>> stack;
    int res = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (!stack.empty() && value == stack.back().first) {
            stack.back().second++;
        } else {
            if (!stack.empty() && stack.back().second >= 3) {
                res += stack.back().second;
                stack.pop_back();
            }

            if (!stack.empty() && value == stack.back().first)
                stack.back().second++;
            else
                stack.push_back({ value, 1 });
        }
    }

    if (!stack.empty() && stack.back().second >= 3) {
        res += stack.back().second;
        stack.pop_back();
    }

    cout << res;
}