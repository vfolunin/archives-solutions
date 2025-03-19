#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<string, char> code;
    for (int i = 0; i < size; i++) {
        char c;
        string word;
        cin >> c >> word;
        code[word] = c;
    }

    string s;
    cin >> s;

    string word;
    for (char c : s) {
        word += c;
        if (code.count(word)) {
            cout << code[word];
            word.clear();
        }
    }
}