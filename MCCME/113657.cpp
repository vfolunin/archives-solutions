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

    cout << s;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(')
            cout << ')';
        else
            cout << s[i];
    }
}