#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool parse(string &line, int &i) {
    static string letters = "pqrstuvwxyz";
    if (letters.find(line[i]) != -1) {
        i++;
        return 1;
    }

    if (line[i] == 'N') {
        i++;
        return parse(line, i);
    }

    static string quantors = "CDEI";
    if (quantors.find(line[i]) != -1) {
        i++;
        return parse(line, i) && parse(line, i);
    }

    return 0;
}

bool parse(string &line) {
    int i = 0;
    return parse(line, i) && i == line.size();
}

bool solve() {
    string line;
    if (!(cin >> line))
        return 0;

    cout << (parse(line) ? "YES\n" : "NO\n");
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}