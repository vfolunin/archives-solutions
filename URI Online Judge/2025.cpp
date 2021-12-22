#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    getline(cin, line);
    line += "\n";

    string word;
    for (char c : line) {
        if (isalpha(c)) {
            word += c;
        } else {
            if (word.size() == 10 && word.substr(1, 8) == "oulupukk")
                word = "Joulupukki";
            cout << word << c;
            word.clear();
        }
    }
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