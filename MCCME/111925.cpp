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

    vector<string> words;
    while (cin >> words.emplace_back());

    int res = 0;
    for (int i = 0; i + 1 < words.size(); i++)
        if (isdigit(words[i][0]) && (words[i + 1].starts_with("zajats") || words[i + 1].starts_with("zajts")))
            res += stoi(words[i]);

    cout << res;
}