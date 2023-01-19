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

    string s, a, b;
    cin >> s >> a >> b;

    for (int i = 0; i < s.size(); ) {
        if (s.substr(i, a.size()) == a) {
            cout << b;
            i += a.size();
        } else {
            cout << s[i];
            i++;
        }
    }
}