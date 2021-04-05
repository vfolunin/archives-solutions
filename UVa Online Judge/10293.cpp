#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    map<int, int> lengthCount;

    string word;
    char c;
    cin >> noskipws;

    while (cin >> c) {
        if (c == '#') {
            for (auto &[length, count] : lengthCount)
                cout << length << " " << count << "\n";
            cout << "\n";
            return 1;
        }

        if (isalpha(c)) {
            word += c;
        } else if (c == '\'') {
            continue;
        } else if (c == '-') {
            if (cin.peek() == '\n')
                cin.ignore();
        } else if (!word.empty()) {
            lengthCount[word.size()]++;
            word.clear();
        }
    }

    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}