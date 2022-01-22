#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int n;
    if (!(cin >> n))
        return 0;

    map<string, int> wordCount;
    string word;

    cin >> noskipws;
    while (1) {
        char c;
        if (cin >> c && isalpha(c)) {
            word += tolower(c);
        } else if (word == "endoftext") {
            break;
        } else if (!word.empty()) {
            wordCount[word]++;
            word.clear();
        }
    }

    if (test)
        cout << "\n";

    bool found = 0;
    for (auto &[word, count] : wordCount) {
        if (count == n) {
            found = 1;
            cout << word << "\n";
        }
    }

    if (!found)
        cout << "There is no such word.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}