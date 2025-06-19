#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, windowSize;
    string s;
    cin >> size >> windowSize >> s;

    string res;
    for (int i = 0; i + windowSize <= size; i++)
        res = max(res, s.substr(i, windowSize));

    cout << stoll(res, 0, 2) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}