#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordSize;
    string s;
    cin >> wordSize >> wordSize >> s;

    unordered_set<string> words;
    for (int i = 0; i + wordSize <= s.size(); i++)
        words.insert(s.substr(i, wordSize));

    cout << words.size();
}