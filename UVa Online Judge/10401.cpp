#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;
    int size = s.size();

    vector<vector<long long>> ways(size, vector<long long>(size));
    for (int col = 0; col < size; col++) {
        if (s[col] == '?') {
            for (int row = 0; row < size; row++) {
                if (col) {
                    for (int prevRow = 0; prevRow < size; prevRow++)
                        if (abs(row - prevRow) > 1)
                            ways[row][col] += ways[prevRow][col - 1];
                } else {
                    ways[row][col] = 1;
                }
            }
        } else {
            int row = (isdigit(s[col]) ? s[col] - '1' : s[col] - 'A' + 9);
            if (row >= size) {
                cout << "0\n";
                return 1;
            }            

            if (col) {
                for (int prevRow = 0; prevRow < size; prevRow++)
                    if (abs(row - prevRow) > 1)
                        ways[row][col] += ways[prevRow][col - 1];
            } else {
                ways[row][col] = 1;
            }
        }
    }

    long long res = 0;
    for (int row = 0; row < size; row++)
        res += ways[row][size - 1];

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}