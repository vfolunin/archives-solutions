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

    string text, word = "Sandro";
    cin >> text;

    int minOps = 1e9;
    for (int i = 0; i + word.size() <= text.size(); i++) {
        int ops = 0;
        for (int j = 0; j < word.size(); j++) {
            ops += tolower(text[i + j]) != tolower(word[j]);
            ops += islower(text[i + j]) != islower(word[j]);
        }
        minOps = min(minOps, ops);
    }

    cout << minOps * 5;
}