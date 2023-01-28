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
    getline(cin, s);

    if (s[0] != '_' && !isalpha(s[0])) {
        cout << "NO";
        return 0;
    }

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != '_' && !isalnum(s[i])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}