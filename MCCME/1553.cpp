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

    string letters;
    int wordSize;
    cin >> letters >> wordSize;

    sort(letters.begin(), letters.end());

    set<string> words;
    string mask = string(letters.size() - wordSize, '0') + string(wordSize, '1');
    do {
        string word;
        for (int i = 0; i < letters.size(); i++)
            if (mask[i] == '1')
                word += letters[i];
        words.insert(word);
    } while (next_permutation(letters.begin(), letters.end()));

    for (const string &word : words)
        cout << word << "\n";
}