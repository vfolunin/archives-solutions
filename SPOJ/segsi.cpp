#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getCount(const string &text, const string &word) {
    int res = 0;
    for (int i = 0; i + word.size() <= text.size(); i++)
        res += text.substr(i, word.size()) == word;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text;
    long long count;
    cin >> text >> count;

    string word = "segsi";
    long long res = getCount(text, word) * count;
    if (text.size() >= 5 && getCount(text.substr(text.size() - 4) + text.substr(0, 4), word))
        res += count - 1;

    cout << res;
}