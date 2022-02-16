#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    string text;
    getline(cin, text);

    static vector<string> code = {
        "2", "22", "222",
        "3", "33", "333",
        "4", "44", "444",
        "5", "55", "555",
        "6", "66", "666",
        "7", "77", "777", "7777",
        "8", "88", "888",
        "9", "99", "999", "9999"
    };

    string keys;
    for (char c : text) {
        if (islower(c)) {
            if (!keys.empty() && keys.back() == code[c - 'a'].front())
                keys += " ";
            keys += code[c - 'a'];
        } else {
            if (!keys.empty() && keys.back() == '0')
                keys += " ";
            keys += "0";
        }
    }

    cout << "Case #" << test << ": " << keys << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int test = 1; test <= n; test++)
        solve(test);
}