#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> split(string &line) {
    vector<string> words;
    string word;
    for (char c : line) {
        if (c != ' ') {
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

    string sa, sb;
    getline(cin, sa);
    getline(cin, sb);

    vector<string> a = split(sa);
    for (string &s : a)
        for (char &c : s)
            c = tolower(c);

    vector<string> b = split(sb);
    for (string &s : b)
        for (char &c : s)
            c = tolower(c);

    cout << (a == b ? "YES" : "NO");
}