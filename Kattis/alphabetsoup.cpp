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
    
    string s;
    cin >> s;

    vector<int> seen(26);
    for (char c : s)
        seen[c - 'A'] = 1;

    bool found = 0;
    for (int i = 0; i < seen.size(); i++) {
        if (!seen[i]) {
            cout << (char)(i + 'A');
            found = 1;
        }
    }

    if (!found)
        cout << "Alphabet Soup!";
}