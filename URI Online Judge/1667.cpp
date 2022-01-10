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

    string line, word;
    while (cin >> word) {
        if (word == "<br>") {
            cout << line << "\n";
            line.clear();
        } else if (word == "<hr>") {
            if (!line.empty())
                cout << line << "\n";
            cout << string(80, '-') << "\n";
            line.clear();
        } else if (line.size() + !line.empty() + word.size() <= 80) {
            if (!line.empty())
                line += " ";
            line += word;
        } else {
            cout << line << "\n";
            line = word;
        }
    }
    if (!line.empty())
        cout << line << "\n";
}