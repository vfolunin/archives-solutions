#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isCool(string &s) {
    map<char, int> count;
    for (char c : s)
        count[c]++;

    set<int> countSet;
    for (auto &[_, cnt] : count)
        countSet.insert(cnt);

    return count.size() > 1 && countSet.size() == count.size();
}

bool solve(int test) {
    int wordCount;
    if (!(cin >> wordCount))
        return 0;

    int coolWordCount = 0;
    for (int i = 0; i < wordCount; i++) {
        string word;
        cin >> word;
        coolWordCount += isCool(word);
    }

    cout << "Case " << test << ": " << coolWordCount << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}