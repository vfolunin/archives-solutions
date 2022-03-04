#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Comparator {
    bool operator() (const string &a, const string &b) const {
        return lexicographical_compare(a.rbegin(), a.rend(), b.rbegin(), b.rend());
    }
};

bool solve(int test) {
    set<string, Comparator> words;
    int maxLength = 0;

    while (1) {
        string word;
        if (!getline(cin, word) || word.empty())
            break;

        words.insert(word);
        maxLength = max<int>(maxLength, word.size());
    }

    if (words.empty())
        return 0;

    if (test)
        cout << "\n";
    for (const string &word : words)
        cout << setw(maxLength) << right << word << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}