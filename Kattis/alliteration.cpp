#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    vector<int> count(26);
    for (string word; ss >> word; )
        count[word[0] - 'a']++;

    cout << (char)(max_element(count.begin(), count.end()) - count.begin() + 'a') << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;
    cin.ignore();

    for (int i = 0; i < size; i++)
        solve();
}