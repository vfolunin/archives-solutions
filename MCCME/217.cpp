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

    string a, b;
    cin >> a >> b;

    vector<vector<string>> res(a.size() + 1, vector<string>(b.size() + 1, "#"));
    res[0][0] = "";

    for (int bLen = 1; bLen <= b.size(); bLen++) {
        char bc = b[bLen - 1];
        if (res[0][bLen - 1] != "#" && bc == '*')
            res[0][bLen] = res[0][bLen - 1];
    }

    for (int aLen = 1; aLen <= a.size(); aLen++) {
        char ac = a[aLen - 1];

        if (res[aLen - 1][0] != "#" && ac == '*')
            res[aLen][0] = res[aLen - 1][0];

        for (int bLen = 1; bLen <= b.size(); bLen++) {
            char bc = b[bLen - 1];

            if (ac == '*') {

                if (bc == '*') {

                    if (res[aLen - 1][bLen] == "#" || res[aLen][bLen - 1] == "#")
                        res[aLen][bLen] = res[aLen - 1][bLen] != "#" ? res[aLen - 1][bLen] : res[aLen][bLen - 1];
                    else
                        res[aLen][bLen] = res[aLen - 1][bLen].size() < res[aLen][bLen - 1].size() ? res[aLen - 1][bLen] : res[aLen][bLen - 1];

                } else if (bc == '?') {

                    if (res[aLen - 1][bLen] == "#" || res[aLen][bLen - 1] == "#")
                        res[aLen][bLen] = res[aLen - 1][bLen] != "#" ? res[aLen - 1][bLen] : res[aLen][bLen - 1] + 'a';
                    else
                        res[aLen][bLen] = res[aLen - 1][bLen].size() < res[aLen][bLen - 1].size() + 1 ? res[aLen - 1][bLen] : res[aLen][bLen - 1] + 'a';

                } else {

                    if (res[aLen - 1][bLen] == "#" || res[aLen][bLen - 1] == "#")
                        res[aLen][bLen] = res[aLen - 1][bLen] != "#" ? res[aLen - 1][bLen] : res[aLen][bLen - 1] + bc;
                    else
                        res[aLen][bLen] = res[aLen - 1][bLen].size() < res[aLen][bLen - 1].size() + 1 ? res[aLen - 1][bLen] : res[aLen][bLen - 1] + bc;

                }

            } else if (ac == '?') {

                if (bc == '*') {

                    if (res[aLen - 1][bLen] == "#" || res[aLen][bLen - 1] == "#")
                        res[aLen][bLen] = (res[aLen - 1][bLen] != "#" ? res[aLen - 1][bLen] + 'a' : res[aLen][bLen - 1]);
                    else
                        res[aLen][bLen] = (res[aLen - 1][bLen].size() + 1 < res[aLen][bLen - 1].size() ? res[aLen - 1][bLen] + 'a' : res[aLen][bLen - 1]);

                } else if (bc == '?') {

                    if (res[aLen - 1][bLen - 1] != "#")
                        res[aLen][bLen] = res[aLen - 1][bLen - 1] + 'a';

                } else {

                    if (res[aLen - 1][bLen - 1] != "#")
                        res[aLen][bLen] = res[aLen - 1][bLen - 1] + bc;

                }

            } else {

                if (bc == '*') {

                    if (res[aLen - 1][bLen] == "#" || res[aLen][bLen - 1] == "#")
                        res[aLen][bLen] = res[aLen - 1][bLen] != "#" ? res[aLen - 1][bLen] + ac : res[aLen][bLen - 1];
                    else
                        res[aLen][bLen] = res[aLen - 1][bLen].size() + 1 < res[aLen][bLen - 1].size() ? res[aLen - 1][bLen] + ac : res[aLen][bLen - 1];

                } else if (bc == '?') {

                    if (res[aLen - 1][bLen - 1] != "#")
                        res[aLen][bLen] = res[aLen - 1][bLen - 1] + ac;

                } else {

                    if (res[aLen - 1][bLen - 1] != "#" && ac == bc)
                        res[aLen][bLen] = res[aLen - 1][bLen - 1] + ac;

                }

            }
        }
    }

    if (res[a.size()][b.size()] == "#")
        cout << "No solution!";
    else
        cout << res[a.size()][b.size()];
}