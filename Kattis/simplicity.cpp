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

    vector<int> letterCount(26);
    for (char letter : word)
        letterCount[letter - 'a']++;

    sort(letterCount.rbegin(), letterCount.rend());

    cout << word.size() - letterCount[0] - letterCount[1];
}