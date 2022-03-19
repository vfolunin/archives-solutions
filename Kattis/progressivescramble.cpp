#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCode(char c) {
    return isalpha(c) ? c - 'a' + 1 : 0;
}

void print(int code) {
    cout << (code ? (char)(code - 1 + 'a') : ' ');
}

void solve() {
    string type, text;
    cin >> type;
    cin.ignore();
    getline(cin, text);

    int sum = 0;
    if (type == "e") {
        for (char c : text) {
            sum += getCode(c);
            print(sum % 27);
        }
    } else {
        for (char c : text) {
            int code = (getCode(c) + 27 - sum % 27) % 27;
            sum += code;
            print(code);
        }
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}