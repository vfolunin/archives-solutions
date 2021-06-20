#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long parseProgram(vector<string> &lines, int &pos);

long long parseCond(vector<string> &lines, int &pos) {
    long long res = 0;
    pos++;
    res += parseProgram(lines, pos);
    pos++;
    res += parseProgram(lines, pos);
    pos++;
    return res;
}

long long parseProgram(vector<string> &lines, int &pos) {
    long long res = 1;
    while (lines[pos] == "IF")
        res *= parseCond(lines, pos);
    return res;
}

void solve() {
    vector<string> lines;
    while (1) {
        string line;
        cin >> line;

        if (line != "S")
            lines.push_back(line);

        if (line == "ENDPROGRAM")
            break;
    }

    int pos = 0;
    cout << parseProgram(lines, pos) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}