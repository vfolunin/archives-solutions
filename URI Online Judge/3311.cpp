#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool compare(const string &a, const string &b) {
    return a[0] < b[0];
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    stable_sort(words.begin(), words.end(), compare);

    for (string &word : words)
        cout << word << "\n";
}