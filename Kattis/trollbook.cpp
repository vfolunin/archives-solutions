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

    int size;
    cin >> size;

    vector<string> words(size);
    for (int i = 0; i < words.size(); i++) {
        string word;
        int index;
        cin >> word >> index;

        words[index - 1] = word;
    }

    for (int i = 0; i < words.size(); i++)
        cout << (i ? " " : "") << words[i];
}