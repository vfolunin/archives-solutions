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

    int limit;
    cin >> limit;

    string row;
    for (string word; cin >> word; ) {
        if (row.size() + !row.empty() + word.size() <= limit) {
            if (!row.empty())
                row += " ";
            row += word;
        } else {
            cout << row << "\n";
            row = word;
        }
    }
    cout << row;
}