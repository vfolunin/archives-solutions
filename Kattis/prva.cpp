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

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (string &row : a)
        cin >> row;

    string minWord;
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '#')
                continue;

            if (!y || a[y - 1][x] == '#') {
                string word;
                for (int i = y; i < h && a[i][x] != '#'; i++)
                    word += a[i][x];
                if (word.size() >= 2 && (minWord.empty() || minWord > word))
                    minWord = word;
            }

            if (!x || a[y][x - 1] == '#') {
                string word;
                for (int i = x; i < w && a[y][i] != '#'; i++)
                    word += a[y][i];
                if (word.size() >= 2 && (minWord.empty() || minWord > word))
                    minWord = word;
            }
        }
    }

    cout << minWord;
}