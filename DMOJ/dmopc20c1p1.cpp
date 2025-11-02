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

    int type = 0;
    type += s.find('C') != -1;
    type += s.find('M') != -1;

    if (type == 2)
        cout << "NEGATIVE MARKS\n";
    else if (type == 1)
        cout << "FAIL\n";
    else
        cout << "PASS\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}