#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    cin >> s;

    if (s == "0")
        return 0;

    vector<int> last(26, -1);
    vector<vector<int>> p(s.size(), vector<int>(26));

    double sum = 0, count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i)
            for (int j = 0; j < 26; j++)
                p[i][j] += p[i - 1][j];
        p[i][s[i] - 'a']++;

        if (last[s[i] - 'a'] != -1) {
            int uniqueCount = 0;
            for (int j = 0; j < 26; j++)
                uniqueCount += p[i][j] > p[last[s[i] - 'a']][j];
            sum += uniqueCount - 1;
            count++;
        }

        last[s[i] - 'a'] = i;
    }

    if (!count) {
        cout << "NaN\n";
    } else {
        cout.precision(4);
        cout << fixed << sum / count << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}