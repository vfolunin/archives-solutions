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

    string value;
    for (char c; cin >> c; ) {
        if (isdigit(c)) {
            value += c;
        } else {
            if (!value.empty()) {
                cout << value << "\n";
                value.clear();
            }
            cout << c << "\n";
        }
    }
    if (!value.empty())
        cout << value << "\n";
}