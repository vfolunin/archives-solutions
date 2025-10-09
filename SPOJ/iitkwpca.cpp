#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    unordered_set<string> words;
    for (string word; ss >> word; )
        words.insert(word);

    cout << words.size() << "\n";
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