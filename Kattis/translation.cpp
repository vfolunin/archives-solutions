#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<string> a(size);
    for (string &s : a)
        cin >> s;

    int dictSize;
    cin >> dictSize;

    unordered_map<string, string> dict;
    for (int i = 0; i < dictSize; i++) {
        string word, translation;
        cin >> word >> translation;
        dict[word] = translation;
    }

    for (string &s : a)
        cout << dict[s] << " ";
}