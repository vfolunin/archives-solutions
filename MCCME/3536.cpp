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

    int n;
    cin >> n;

    vector<string> img = {
        "+___ ",
        "|1 / ",
        "|__\\ ",
        "|    "
    };

    for (int i = 0; i < img.size(); i++) {
        string row;
        for (int j = 0; j < n; j++) {
            row += img[i];
            if (i == 1)
                row[row.size() - 4] += j;
        }
        cout << row << "\n";
    }
}