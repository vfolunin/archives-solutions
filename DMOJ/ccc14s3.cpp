#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    reverse(a.begin(), a.end());
    vector<int> stack;

    for (int i = 0, value = 1; i < a.size(); i++) {
        stack.push_back(a[i]);

        while (!stack.empty() && stack.back() == value) {
            stack.pop_back();
            value++;
        }
    }

    cout << (stack.empty() ? "Y\n" : "N\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}