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

bool isUmm(string &word) {
    for (char c : word)
        if (isalpha(c) && c != 'u' && c != 'm')
            return 0;
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string umm;
    for (string &word : readWords())
        if (isUmm(word))
            for (char c : word)
                if (isalpha(c))
                    umm += c;

    for (int i = 0; i < umm.size(); i += 7) {
        char c = 0;
        for (int j = 0; j < 7; j++)
            c = c * 2 + (umm[i + j] == 'u');
        cout << c;
    }
}