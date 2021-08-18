#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    string s;
    string vowels = "aeiou", consonants = "bcdfghjklmnpqrstvwxyz";
    vector<int> used;
    double totalSbc, totalCount;

    double sbc(string &s) {
        static vector<double> p = {
            12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15,
            6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02, 0.22, 0.90, 0.52
        };
        double res = 0;
        for (int i = 0; i < s.size(); i++)
            res += (i + 1) * p[s[i] - 'a'];
        return res;
    }

    void rec(int index, int size) {
        if (index == size) {
            totalSbc += sbc(s);
            totalCount++;
            return;
        }
        string &letters = (index % 2 ? vowels : consonants);
        for (char c : letters) {
            if (used[c - 'a'] == 2)
                continue;
            used[c - 'a']++;
            s.push_back(c);
            rec(index + 1, size);
            used[c - 'a']--;
            s.pop_back();
        }
    }

    string getRes(string &word) {
        used.assign(26, 0);
        totalSbc = totalCount = 0;
        s = word.substr(0, 1);
        rec(1, word.size());
        return sbc(word) < totalSbc / totalCount ? "below" : "above or equal";
    }
};

void solve() {
    string word;
    cin >> word;

    Solver solver;
    cout << solver.getRes(word) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}