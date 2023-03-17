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

    vector<double> a(size);
    for (double &value : a)
        cin >> value;

    vector<double> b = a, stack;
    sort(b.begin(), b.end());
    int bi = 0;
    for (double value : a) {
        stack.push_back(value);
        while (!stack.empty() && stack.back() == b[bi]) {
            stack.pop_back();
            bi++;
        }
    }

    cout << stack.empty() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}