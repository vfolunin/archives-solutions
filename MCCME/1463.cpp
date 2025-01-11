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
    for (string word; cin >> word; )
        words.push_back(word);

    for (int i = 0; i < words.size(); i++) {
        if (i)
            cout << " ";
        cout << words[i];
    }
}