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

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<int> letterCount(26);
    for (string s : { s1, s2 })
        for (char c : s)
            letterCount[c - 'A']--;

    for (char c : s3)
        letterCount[c - 'A']++;

    cout << (count(letterCount.begin(), letterCount.end(), 0) == letterCount.size() ? "YES" : "NO");
}