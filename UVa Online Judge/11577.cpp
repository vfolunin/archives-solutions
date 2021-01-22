#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    getline(cin, line);

    vector<int> letterFrequency(26);
    for (char c : line)
        if (isalpha(c))
            letterFrequency[tolower(c) - 'a']++;

    int maxFrequency = *max_element(letterFrequency.begin(), letterFrequency.end());
    for (int i = 0; i < 26; i++)
        if (letterFrequency[i] == maxFrequency)
            cout << (char)('a' + i);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve();
}