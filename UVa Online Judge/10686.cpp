#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Category {
    string name;
    set<string> words;
    int threshold;
};

istream &operator >> (istream &in, Category &c) {
    int n;
    in >> c.name >> n >> c.threshold;
    for (int i = 0; i < n; i++) {
        string word;
        in >> word;
        c.words.insert(word);
    }
    return in;
}

set<string> readWords() {
    string line;
    getline(cin, line);

    set<string> words;
    while (getline(cin, line) && !line.empty()) {
        string word;
        for (char c : line) {
            if (isalpha(c)) {
                word += c;
            } else if (!word.empty()) {
                words.insert(word);
                word = "";
            }
        }
        if (!word.empty())
            words.insert(word);
    }
    return words;
}

void solve() {
    int categoryCount;
    cin >> categoryCount;

    vector<Category> categories(categoryCount);
    for (Category &c : categories)
        cin >> c;

    set<string> words = readWords();
    vector<string> res;

    for (Category &category : categories) {
        int selectedWordCount = 0;
        for (const string &word : words)
            selectedWordCount += category.words.count(word);
        if (selectedWordCount >= category.threshold)
            res.push_back(category.name);
    }

    if (res.empty())
        res.push_back("SQF Problem.");

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? "," : "\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}