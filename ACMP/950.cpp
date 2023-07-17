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

    char symbol = 'a';
    for (char c : s) {
        if (c == '1') {
            cout << symbol;
            symbol = 'a';
        } else {
            symbol++;
        }
    }
}