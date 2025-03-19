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

    string word = "DOG";
    vector<int> count(s.size());

    for (int i = 1; i < s.size(); i++) {
        if (count[i - 1] && (word.find(s[i - 1]) + 1) % word.size() == word.find(s[i]))
            count[i] = count[i - 1] + 1;
        else if (s[i] == word[0])
            count[i] = 1;
    }

    cout << *max_element(count.begin(), count.end());
}