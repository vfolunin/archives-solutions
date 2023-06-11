#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool canFind(string text, string &word) {
    while (text.size() <= word.size())
        text += text;
    text += text;
    return text.find(word) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text, word;
    cin >> text >> word;

    if (canFind(text, word) || canFind({ text.rbegin(), text.rend() }, word))
        cout << "YES";
    else
        cout << "NO";
}