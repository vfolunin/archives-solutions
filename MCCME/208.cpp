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

    vector<vector<int>> ways(s.size() + 1, vector<int>(s.size() + 2));
    ways[0][0] = 1;

    for (int len = 1; len <= s.size(); len++) {
        for (int balance = 0; balance <= len; balance++) {
            if (s[len - 1] != ')' && balance)
                ways[len][balance] += ways[len - 1][balance - 1];
            if (s[len - 1] != '(')
                ways[len][balance] += ways[len - 1][balance + 1];
        }
    }

    cout << ways[s.size()][0];
}