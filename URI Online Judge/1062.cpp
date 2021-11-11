#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;
    if (!n)
        return 0;

    vector<int> a(n);
    while (1) {
        cin >> a[0];
        if (!a[0])
            break;
        for (int i = 1; i < n; i++)
            cin >> a[i];

        vector<int> stack;
        for (int val = 1, i = 0; val <= n; val++) {
            stack.push_back(val);
            while (!stack.empty() && stack.back() == a[i]) {
                stack.pop_back();
                i++;
            }
        }

        cout << (stack.empty() ? "Yes\n" : "No\n");
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}