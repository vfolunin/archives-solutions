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

    vector<string> reg(10);
    for (string &s : reg)
        cin >> s;

    vector<string> a(10);
    vector<int> rowCount(10), colCount(10), regCount(10);
    for (int y = 0; y < a.size(); y++) {
        cin >> a[y];
        for (int x = 0; x < a.size(); x++) {
            if (a[y][x] == '*') {
                rowCount[y]++;
                colCount[x]++;
                regCount[reg[y][x] - '0']++;

                static vector<int> dy = { -1, -1, -1, 0 };
                static vector<int> dx = { -1, 0, 1, -1 };
                for (int d = 0; d < dy.size(); d++) {
                    int ty = y + dy[d];
                    int tx = x + dx[d];

                    if (0 <= ty && 0 <= tx && a[ty][tx] == '*') {
                        cout << "invalid";
                        return 0;
                    }
                }
            }
        }
    }

    if (count(rowCount.begin(), rowCount.end(), 2) == rowCount.size() &&
        count(colCount.begin(), colCount.end(), 2) == colCount.size() &&
        count(regCount.begin(), regCount.end(), 2) == regCount.size())
        cout << "valid";
    else
        cout << "invalid";
}