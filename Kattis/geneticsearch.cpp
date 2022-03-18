#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCount(const string &word, string text) {
    text = word + "#" + text;
    vector<int> p(text.size());
    int count = 0;
    for (int i = 1; i < text.size(); i++) {
        int border = p[i - 1];
        while (border > 0 && text[i] != text[border])
            border = p[border - 1];
        p[i] = border + (text[i] == text[border]);
        count += p[i] == word.size();
    }
    return count;
}

bool solve() {
    string word, text;
    if (!(cin >> word >> text))
        return 0;

    int count1 = getCount(word, text);

    set<string> words2;
    for (int i = 0; i < word.size(); i++)
        words2.insert(word.substr(0, i) + word.substr(i + 1));

    int count2 = 0;
    for (const string &word : words2)
        count2 += getCount(word, text);

    set<string> words3;
    for (int i = 0; i < word.size(); i++)
        for (char c : string("ACGT"))
            words3.insert(word.substr(0, i) + c + word.substr(i));
    for (char c : string("ACGT"))
        words3.insert(word + c);

    int count3 = 0;
    for (const string &word : words3)
        count3 += getCount(word, text);

    cout << count1 << " " << count2 << " " << count3 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}