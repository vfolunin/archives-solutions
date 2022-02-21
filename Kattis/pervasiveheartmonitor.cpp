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
    if (words.empty())
        return 0;

    double num = 0, den = 0;
    vector<string> name;
    for (string &word : words) {
        if (isdigit(word[0])) {
            num += stod(word);
            den++;
        } else {
            name.push_back(word);
        }
    }

    cout << fixed << num / den;
    for (string &word : name)
        cout << " " << word;
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}