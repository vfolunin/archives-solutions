#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int test;
    string s;
    cin >> test >> s;

    cout << test << " ";
    if (next_permutation(s.begin(), s.end()))
        cout << s << "\n";
    else
        cout << "BIGGEST\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}