#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const string &a, const string &b) {
    return a.size() < b.size();
}

bool solve(int test) {
    int wordCount;
    cin >> wordCount;

    if (!wordCount)
        return 0;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    stable_sort(words.begin(), words.end(), compare);

    cout << "SET " << test << "\n";
    for (int i = 0; i < wordCount; i += 2)
        cout << words[i] << "\n";
    for (int i = wordCount - 1 - (wordCount % 2); i >= 0; i -= 2)
        cout << words[i] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}