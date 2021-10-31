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

bool solve() {
    vector<string> words = readWords();
    if (words[0] == "*")
        return 0;

    for (int i = 1; i < words.size(); i++) {
        if (tolower(words[i][0]) != tolower(words[0][0])) {
            cout << "N\n";
            return 1;
        }
    }

    cout << "Y\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}