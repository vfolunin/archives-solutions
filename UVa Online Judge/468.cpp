#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string sortByFreq(string &s) {
    map<char, int> count;
    for (char c : s)
        if (isalpha(c))
            count[c]++;

    vector<pair<int, char>> freqs;
    for (char c = 'a'; c <= 'z'; c++)
        freqs.push_back({ -count[c], c });
    for (char c = 'A'; c <= 'Z'; c++)
        freqs.push_back({ -count[c], c });
    sort(freqs.begin(), freqs.end());

    string res;
    for (auto &[_, c] : freqs)
        res += c;
    return res;
}

void solve(int test) {
    string a, b;
    cin.ignore();
    getline(cin, a);
    getline(cin, b);

    string sortedA = sortByFreq(a);
    string sortedB = sortByFreq(b);
    map<char, char> code;
    for (int i = 0; i < sortedA.size(); i++)
        code[sortedB[i]] = sortedA[i];

    for (char &c : b)
        if (isalpha(c))
            c = code[c];

    if (test)
        cout << "\n";
    cout << b << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++)
        solve(i);
}