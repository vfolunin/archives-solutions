#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readStrings() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    vector<string> tokens;
    string token;
    while (ss >> token)
        tokens.push_back(token);
    return tokens;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    map<string, string> dictionary;
    while (1) {
        vector<string> tokens = readStrings();
        if (tokens.empty())
            break;
        dictionary[tokens[1]] = tokens[0];
    }

    string word;
    while (cin >> word)
        cout << (dictionary.count(word) ? dictionary[word] : "eh") << "\n";
}