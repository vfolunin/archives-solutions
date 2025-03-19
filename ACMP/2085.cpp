#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isVowel(char c) {
    string vowels = "AEIOUY";
    return vowels.find(c) != -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<int> count(s.size(), 1);
    for (int i = 1; i < s.size(); i++)
        if (isVowel(s[i - 1]) != isVowel(s[i]))
            count[i] = count[i - 1] + 1;

    cout << *max_element(count.begin(), count.end());
}