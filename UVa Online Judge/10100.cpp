#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<string> readWords(string &line) {
    vector<string> words;
    string word;

    for (char c : line) {
        if (isalnum(c)) {
            word += c;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }
    if (!word.empty())
        words.push_back(word);

    return words;
}

int getLcs(const vector<string> &a, const vector<string> &b) {
    vector<vector<int>> lcs(a.size() + 1, vector<int>(b.size() + 1));
    int res = 0;

    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            res = max(res, lcs[i][j]);
        }
    }

    return res;
}

bool solve(int test) {
    string a, b;
    if (!getline(cin, a))
        return 0;
    getline(cin, b);

    cout << setw(2) << test << ". ";
    if (a.empty() || b.empty())
        cout << "Blank!\n";
    else
        cout << "Length of longest match: " << getLcs(readWords(a), readWords(b)) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}