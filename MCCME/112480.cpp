#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

set<char> read() {
    string s;
    cin >> s;
    return { s.begin(), s.end() };
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    set<char> a = read(), b = read();

    bool found = 0;
    for (char c : a) {
        if (b.count(c)) {
            cout << c;
            found = 1;
        }
    }

    if (!found)
        cout << "NO";
}