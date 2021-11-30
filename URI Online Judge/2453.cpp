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

string decode(string &word) {
    string res;
    for (int i = 1; i < word.size(); i += 2)
        res += word[i];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> words = readWords();
    
    for (int i = 0; i < words.size(); i++)
        cout << decode(words[i]) << (i + 1 < words.size() ? " " : "\n");
}