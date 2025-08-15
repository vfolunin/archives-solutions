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

    vector<int> row(8), col(8);
    for (int y = 0; y < row.size(); y++) {
        string s;
        cin >> s;

        for (int x = 0; x < col.size(); x++) {
            if (s[x] == 'R')
                row[y] = col[x] = 1;
        }
    }

    cout << count(row.begin(), row.end(), 0) * count(col.begin(), col.end(), 0);
}