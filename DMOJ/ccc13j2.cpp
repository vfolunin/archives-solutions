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

    string letters = "IOSHZXN";
    for (char c : s) {
        if (letters.find(c) == -1) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}