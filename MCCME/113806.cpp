#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int wordCount;
    cin >> wordCount;

    vector<string> words(wordCount);
    unordered_map<string, bitset<20000>> indexes;
    for (int i = 0; i < words.size(); i++) {
        cin >> words[i];
        indexes[words[i]].set(i);
    }

    long long res = 0;
    for (int i = 0; i < words.size(); i++) {
        bitset<20000> cur;
        for (int l = 0; l < words[i].size(); l++)
            for (int r = l; r < words[i].size(); r++)
                if (auto it = indexes.find(words[i].substr(l, r - l + 1)); it != indexes.end())
                    cur |= it->second;
        res += cur.count() - 1;
    }

    cout << res;
}