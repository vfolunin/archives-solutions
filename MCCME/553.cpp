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
    
    string word, text;
    cin >> word >> word >> word >> text;

    map<char, int> wordCount;
    for (char c : word)
        wordCount[c]++;

    map<char, int> windowCount;
    for (int i = 0; i < word.size(); i++)
        windowCount[text[i]]++;

    int res = windowCount == wordCount;
    for (int i = word.size(); i < text.size(); i++) {
        if (!--windowCount[text[i - word.size()]])
            windowCount.erase(text[i - word.size()]);
        windowCount[text[i]]++;
        res += windowCount == wordCount;
    }

    cout << res;
}