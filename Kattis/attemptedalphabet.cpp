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

    bool found = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (s.find(c) == -1) {
            found = 1;
            cout << c;
        }
    }

    if (!found)
        cout << "Good job!";
}