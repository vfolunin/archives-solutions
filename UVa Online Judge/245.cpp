#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<string> words;
    string word;
    
    cin >> noskipws;
    while (1) {
        char c;
        cin >> c;

        if (isalpha(c)) {
            word += c;
        } else {
            if (!word.empty()) {
                cout << word;
                words.push_back(word);
            }
            word.clear();

            if (isdigit(c)) {
                int num = c - '0';
                while (isdigit(cin.peek())) {
                    cin >> c;
                    num = num * 10 + c - '0';
                }
                if (!num)
                    break;
                cout << words[words.size() - num];
                rotate(words.end() - num, words.end() - num + 1, words.end());
            } else {
                cout << c;
            }
        }
    }
}