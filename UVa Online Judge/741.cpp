#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    string s;
    int pos;
    cin >> s >> pos;

    if (s == "END" && !pos)
        return 0;

    vector<string> a(s.size(), string(s.size(), ' '));
    for (int j = s.size() - 1; j >= 0; j--) {
        for (int i = 0; i < s.size(); i++)
            a[i][j] = s[i];
        sort(a.begin(), a.end());
    }

    if (test)
        cout << "\n";
    cout << a[pos - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}