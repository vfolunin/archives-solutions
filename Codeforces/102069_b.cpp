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
    cin >> s >> s;

    for (int i = 1; i < s.size(); i++) {
        if (s[0] != s[i]) {
            cout << "Yes\n1 " << i + 1 << " 1";
            return 0;
        }
    }

    cout << "No";
}