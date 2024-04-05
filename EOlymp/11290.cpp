#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getScore(string &s) {
    static string letters = "XJQKA";
    int score = 0;

    for (char c : s)
        score += letters.find(c);

    return score;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    int res = 0;
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;

        res += getScore(s);
    }

    cout << res;
}