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

    int size, width;
    string s;
    cin >> size >> width >> s;

    set<string> seen;
    for (int i = 0; i + width <= s.size(); i++) {
        if (seen.count(s.substr(i, width))) {
            cout << "YES";
            return 0;
        }
        seen.insert(s.substr(i, width));
    }

    cout << "NO";
}