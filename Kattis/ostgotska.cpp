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

    vector<string> words = readWords();

    int num = 0, den = words.size();
    for (string &word : words)
        num += word.find("ae") != -1;

    if (num * 100 >= den * 40)
        cout << "dae ae ju traeligt va";
    else
        cout << "haer talar vi rikssvenska";
}