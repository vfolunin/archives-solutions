#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int count = 0;
    for (int i = 1; i < s.size(); i++)
        count += s[i - 1] == s[i];

    cout << (count % 2 ? "Aayush\n" : "Akash\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}