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
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);

    return words;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    cin >> line;

    int count = 0;
    for (string part : split(line, ';')) {
        if (part.find('-') == -1) {
            count++;
        } else {
            vector<string> segment = split(part, '-');
            count += stoi(segment[1]) - stoi(segment[0]) + 1;
        }
    }
    
    cout << count;
}