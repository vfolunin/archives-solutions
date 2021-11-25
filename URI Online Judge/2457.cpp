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

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    getline(cin, line);

    vector<string> words = readWords();

    double num = 0, den = words.size();
    for (string &word : words)
        num += word.find(line[0]) != -1;

    cout.precision(1);
    cout << fixed << 100 * num / den << "\n";
}