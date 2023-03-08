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

    char c;
    while (cin >> c) {
        if (c == '@') {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}