#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int editDistance(string &a, string &b) {
    vector<vector<int>> dist(a.size() + 1, vector<int>(b.size() + 1));
    for (int na = 1; na <= a.size(); na++)
        dist[na][0] = 3 * na;
    for (int nb = 1; nb <= b.size(); nb++)
        dist[0][nb] = 3 * nb;
    for (int na = 1; na <= a.size(); na++) {
        for (int nb = 1; nb <= b.size(); nb++) {
            if (a[na - 1] == b[nb - 1])
                dist[na][nb] = dist[na - 1][nb - 1];
            else
                dist[na][nb] = min(dist[na - 1][nb - 1] + 5, min(dist[na - 1][nb], dist[na][nb - 1]) + 3);
        }
    }
    return dist[a.size()][b.size()];
}

string getSubstitute(vector<string> &dict, string &word) {
    if (word.empty())
        return "";
    string bestWord;
    int bestDist = 1e9;
    for (string &dictWord : dict) {
        int dist = editDistance(word, dictWord);
        if (bestDist > dist) {
            bestDist = dist;
            bestWord = dictWord;
        }
    }
    return bestWord;
}

bool solve(int test) {
    int dictSize;
    if (!(cin >> dictSize))
        return 0;

    vector<string> dict(dictSize);
    for (string &word : dict)
        cin >> word;

    int textSize;
    cin >> textSize;
    cin.ignore();

    if (test)
        cout << "\n";
    while (1) {
        string line;
        if (!getline(cin, line) || line.empty())
            break;

        string word;
        for (char c : line) {
            if (c != ' ') {
                word += c;
            } else {
                cout << getSubstitute(dict, word) << " ";
                word.clear();
            }
        }
        cout << getSubstitute(dict, word) << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}