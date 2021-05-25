#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    vector<int> avail, taken;
    int len;
    
    Solver(string &s, int len) : avail(26), taken(26), len(len) {
        for (char c : s)
            avail[c - 'a']++;
    }

    void rec(int c, int curLen) {
        if (c == 26 || curLen == len) {
            if (curLen == len) {
                for (int c = 0; c < 26; c++)
                    cout << string(taken[c], 'a' + c);
                cout << "\n";
            }
            return;
        }
        for (taken[c] = avail[c]; taken[c] > 0; taken[c]--)
            if (curLen + taken[c] <= len)
                rec(c + 1, curLen + taken[c]);
        rec(c + 1, curLen);
    }
};

bool solve() {
    string s;
    int len;
    if (!(cin >> s >> len))
        return 0;

    Solver solver(s, len);
    solver.rec(0, 0);
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}