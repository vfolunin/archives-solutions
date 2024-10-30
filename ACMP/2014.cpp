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

    string word;
    cin >> word;

    string s = "ейлнопрэч";
    vector<string> words;
    for (int a = 0; a < s.size(); a++)
        for (int b = a + 1; b < s.size(); b++)
            for (int c = b + 1; c < s.size(); c++)
                for (int d = c + 1; d < s.size(); d++)
                    words.push_back(string(1, s[a]) + s[b] + s[c] + s[d]);

    cout << lower_bound(words.begin(), words.end(), word) - words.begin() + 1;
}