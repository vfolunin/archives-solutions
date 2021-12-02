#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isSubsequence(string &a, string &b) {
    int i = 0;
    for (char c : b) {
        while (i < a.size() && a[i] != c)
            i++;
        if (i == a.size())
            return 0;
        i++;
    }
    return 1;
}

void solve() {
    string a;
    int n;
    cin >> a >> n;

    for (int i = 0; i < n; i++) {
        string b;
        cin >> b;
        cout << (isSubsequence(a, b) ? "Yes\n" : "No\n");
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}