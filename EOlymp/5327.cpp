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

    int open = 0;
    for (char c : s) {
        if (c == '(')
            open++;
        else
            open--;

        if (open < 0) {
            cout << "NO";
            return 0;
        }
    }

    cout << (open ? "NO" : "YES");
}