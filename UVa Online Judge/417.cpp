#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> words;

void generate(const string &word) {
    if (!word.empty())
        words.push_back(word);
    if (word.size() < 5)
        for (char letter = (word.empty() ? 'a' : word.back() + 1); letter <= 'z'; letter++)
            generate(word + letter);
}

bool compare(const string &a, const string &b) {
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;
    
    int index = lower_bound(words.begin(), words.end(), s, compare) - words.begin();
    if (index == words.size() || words[index] != s)
        cout << "0\n";
    else
        cout << index + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    generate("");
    sort(words.begin(), words.end(), compare);
    while (solve());
}