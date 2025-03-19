#include <iostream>
#include <algorithm>
#include <cmath>
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

    if (s.find("bb") != -1) {
        cout << "NO";
        return 0;
    }

    for (int size = 1; size * 3 <= s.size(); size++) {
        for (int from = 0; from + size * 3 <= s.size(); from++) {
            if (s.substr(from, size) == s.substr(from + size, size) &&
                s.substr(from, size) == s.substr(from + size * 2, size)) {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";
}