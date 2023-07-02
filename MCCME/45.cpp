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
 
    int stackCount;
    cin >> stackCount;

    if (stackCount == 1)
        return 0;

    vector<vector<int>> stack(stackCount);
    for (int i = 0; i < stackCount; i++) {
        int size;
        cin >> size;
        stack[i].resize(size);
        for (int &value : stack[i]) {
            cin >> value;
            value--;
        }
    }

    vector<pair<int, int>> res;

    if (stackCount == 2) {
        for (int i = 0; i < stackCount; i++) {
            while (!stack[i].empty() && stack[i].back() != i) {
                res.push_back({ i, i ^ 1 });
                stack[i ^ 1].push_back(stack[i].back());
                stack[i].pop_back();
            }
            if (count(stack[i].begin(), stack[i].end(), i ^ 1)) {
                cout << 0;
                return 0;
            }
        }
    } else {
        for (int i = 1; i < stackCount; i++) {
            while (!stack[i].empty()) {
                res.push_back({ i, 0 });
                stack[0].push_back(stack[i].back());
                stack[i].pop_back();
            }
        }
        while (!stack[0].empty()) {
            int to = max(stack[0].back(), 1);
            res.push_back({ 0, to });
            stack[to].push_back(stack[0].back());
            stack[0].pop_back();
        }
        while (!stack[1].empty()) {
            int to = stack[1].back() ? 2 : 0;
            res.push_back({ 1, to });
            stack[to].push_back(stack[1].back());
            stack[1].pop_back();
        }
        while (!stack[2].empty() && stack[2].back() == 1) {
            res.push_back({ 2, 1 });
            stack[1].push_back(stack[2].back());
            stack[2].pop_back();
        }
    }

    for (auto &[a, b] : res)
        cout << a + 1 << " " << b + 1 << "\n";
}