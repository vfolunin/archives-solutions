#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool areSimilar(string &a, string &b) {
    if (a.size() != b.size())
        return 0;

    int diff = 0;
    for (int i = 0; i < a.size(); i++)
        diff += a[i] != b[i];
    return diff == 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int nameCount;
    cin >> nameCount;

    vector<string> names(nameCount);
    for (string &name : names)
        cin >> name;

    int wordCount;
    cin >> wordCount;

    vector<int> res(nameCount);

    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;

        for (int j = 0; j < nameCount; j++)
            res[j] += areSimilar(names[j], word);
    }

    for (int value : res)
        cout << value << " ";
}