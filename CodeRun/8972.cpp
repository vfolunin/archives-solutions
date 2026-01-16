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

    string s;
    int wordCount;
    cin >> s >> wordCount;

    vector<string> words(wordCount);
    for (string &word : words)
        cin >> word;

    vector<int> last(s.size() + 1, -1);
    last[0] = -2;
    for (int len = 1; len <= s.size(); len++)
        for (int i = 0; i < words.size(); i++)
            if (words[i].size() <= len && last[len - words[i].size()] != -1 &&
                s.substr(len - words[i].size(), words[i].size()) == words[i])
                last[len] = i;

    vector<string> res;
    for (int len = s.size(); len; len -= words[last[len]].size())
        res.push_back(words[last[len]]);
    reverse(res.begin(), res.end());

    for (string &word : res)
        cout << word << " ";
}