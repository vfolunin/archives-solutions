#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords() {
    string line;
    getline(cin, line);

    vector<string> words;
    stringstream ss(line);
    string word;
    while (ss >> word)
        words.push_back(word);

    return words;
}

bool isWord(string &s) {
    for (int i = 0; i + 1 < s.size(); i++)
        if (!isalpha(s[i]))
            return 0;
    return isalpha(s.back()) || s.back() == '.';
}

bool solve() {
    vector<string> words = readWords();

    if (words.empty())
        return 0;

    int lenSum = 0, lenCount = 0;
    for (string &word : words) {
        if (isWord(word)) {
            lenSum += word.size() - (word.back() == '.');
            lenCount++;
        }
    }

    if (!lenCount || lenSum / lenCount <= 3)
        cout << "250\n";
    else if (lenSum / lenCount <= 5)
        cout << "500\n";
    else
        cout << "1000\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}