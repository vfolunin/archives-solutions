#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> getPos(char c) {
    static vector<string> keyboard = { "qwertyuiop", "asdfghjkl", "zxcvbnm" };
    for (int y = 0; y < keyboard.size(); y++)
        if (int x = keyboard[y].find(c); x != -1)
            return { y, x };
    return { -1, -1 };
}

int getDist(string &a, string &b) {
    int dist = 0;
    for (int i = 0; i < a.size(); i++) {
        auto [ay, ax] = getPos(a[i]);
        auto [by, bx] = getPos(b[i]);
        dist += abs(ay - by) + abs(ax - bx);
    }
    return dist;
}

void solve() {
    string word;
    int hintCount;
    cin >> word >> hintCount;

    vector<pair<int, string>> hints(hintCount);
    for (auto &[dist, hint] : hints) {
        cin >> hint;
        dist = getDist(hint, word);
    }

    sort(hints.begin(), hints.end());

    for (auto &[dist, hint] : hints)
        cout << hint << " " << dist << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}