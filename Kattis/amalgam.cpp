#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getLetterCount() {
    string s;
    cin >> s;

    vector<int> count(26);
    for (char c : s)
        count[c - 'a']++;
    return count;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> aCount = getLetterCount();
    vector<int> bCount = getLetterCount();

    for (int i = 0; i < aCount.size(); i++)
        cout << string(max(aCount[i], bCount[i]), 'a' + i);
}