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

    string word = "HONI";
    int res = 0;

    for (char c : s)
        res += c == word[res % word.size()];
    
    cout << res / word.size();
}