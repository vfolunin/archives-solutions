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

    string line;
    getline(cin, line);

    for (int l = 0, r = line.size() - 1; l < r; l++, r--) {
        while (l < r && !isalpha(line[l]))
            l++;
        while (l < r && !isalpha(line[r]))
            r--;
        if (l < r && line[l] != line[r]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}