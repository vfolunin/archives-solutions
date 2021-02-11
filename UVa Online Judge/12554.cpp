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

    int n;
    cin >> n;

    vector<string> names(n);
    for (string &name : names)
        cin >> name;

    vector<string> words = { "Happy", "birthday", "to", "you", "Rujia" };
    int singer = 0;

    do {
        for (int verse = 0; verse < 4; verse++)
            for (int word = 0; word < 4; word++)
                cout << names[singer++ % n] << ": " << words[word + (word == 3 && verse == 2)] << "\n";
    } while (singer < n);
}