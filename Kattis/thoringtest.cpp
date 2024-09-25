#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

string toLower(string &s) {
    for (char &c : s)
        c = tolower(c);
    return s;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_set<string> words;
    for (int i = 0; i < size; i++) {
        string word;
        cin >> word;

        words.insert(toLower(word));
    }

    for (string word; cin >> word; ) {
        if (!words.count(toLower(word))) {
            cout << "Thore has left the chat";
            return 0;
        }
    }

    cout << "Hi, how do I look today?";
}