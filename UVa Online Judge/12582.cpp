#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string line;
    cin >> line;

    map<char, int> degree;
    vector<char> stack;

    for (char v : line) {
        if (!stack.empty() && stack.back() == v) {
            stack.pop_back();
        } else {
            if (stack.empty()) {
                degree[v];
            } else {
                degree[v] = 1;
                degree[stack.back()]++;
            }
            stack.push_back(v);
        }
    }

    cout << "Case " << test << "\n";
    for (auto &[v, d] : degree)
        cout << v << " = " << d << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}