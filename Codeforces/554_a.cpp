#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    unordered_set<string> values;
    for (int i = 0; i <= s.size(); i++)
        for (char c = 'a'; c <= 'z'; c++)
            values.insert(s.substr(0, i) + c + s.substr(i));

    cout << values.size();
}