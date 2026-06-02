#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    for (int i = 2; i < s.size(); i++) {
        if ((s[i - 1] - 'A' + s[i - 2] - 'A') % 26 != s[i] - 'A') {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}