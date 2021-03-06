#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string line;
    if (!getline(cin, line))
        return 0;

    static string symbol[2] = {
        "<T*O HNM=LRGIPCVEZDBSYFXAWJ UQK",
        ">5@9 %,.+)4&80:;3\"$?#6!/-2' 71("
    };

    int shift = 0;
    for (int i = 0; i < line.size(); i += 5) {
        int code = 0;
        for (int j = 0; j < 5; j++)
            code = code * 2 + line[i + j] - '0';
        if (code == 27)
            shift = 0;
        else if (code == 31)
            shift = 1;
        else
            cout << symbol[shift][code];
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    getline(cin, line);
    getline(cin, line);

    while (solve());
}