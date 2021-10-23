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

    int k = s.find('k');
    int a = count(s.begin(), s.begin() + k, 'a');
    int b = count(s.begin() + k, s.end(), 'a');

    cout << "k" << string(a * b, 'a') << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}