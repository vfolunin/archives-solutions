#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unordered_set<string> words;

    string word;
    while (cin >> word)
        words.insert(word);

    cout << words.size();
}