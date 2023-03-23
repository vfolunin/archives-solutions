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
    getline(cin, s);

    int wordCount = 1;
    for (int i = 1; i < s.size(); i++)
        wordCount += s[i - 1] == ' ' && s[i] != ' ';

    cout << wordCount;
}