#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> button(n);
    for (int &x : button)
        cin >> x;

    vector<int> times(n);
    for (int &x : times)
        cin >> x;

    static vector<string> symbol = {
        " ", ".,?\"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    for (int i = 0; i < n; i++)
        cout << symbol[button[i]][times[i] - 1];
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}