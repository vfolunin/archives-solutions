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
    while (cin >> word)
        words.push_back(word);

    set<string>  compounds;
    for (int i = 0; i < words.size(); i++)
        for (int j = 0; j < words.size(); j++)
            if (i != j)
                compounds.insert(words[i] + words[j]);

    for (const string &word : compounds)
        cout << word << "\n";
}