#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line, char delimiter) {
    vector<string> words;
    string word;

    for (char c : line) {
        if (c != delimiter) {
            word += c;
        } else {
            words.push_back(word);
            word.clear();
        }
    }
    words.push_back(word);

    return words;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    cin >> line;

    vector<string> tokens = split(line, '+');
    set<long long> values;

    for (int mask = 0; mask < (1 << (tokens.size() - 1)); mask++) {
        long long value = 0;

        string token = tokens[0];
        for (int i = 0; i < tokens.size() - 1; i++) {
            if (mask & (1 << i)) {
                token += tokens[1 + i];
            } else {
                value += stoll(token);
                token = tokens[1 + i];
            }
        }
        value += stoll(token);

        values.insert(value);
    }

    cout << values.size();
}