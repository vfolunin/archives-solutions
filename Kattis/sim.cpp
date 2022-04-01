#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string keys;
    getline(cin, keys);

    list<char> text;
    auto it = text.begin();

    for (char key : keys) {
        if (key == '[') {
            it = text.begin();
        } else if (key == ']') {
            it = text.end();
        } else if (key == '<') {
            if (it != text.begin()) {
                it--;
                it = text.erase(it);
            }
        } else {
            text.insert(it, key);
        }
    }

    for (char c : text)
        cout << c;
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}