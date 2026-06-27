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

    string s;
    cin >> s >> s;

    for (int i = 0; i < s.size(); ) {
        if (i + 2 < s.size() && s.substr(i, 3) == "ogo") {
            cout << "***";

            i += 3;
            while (i + 1 < s.size() && s.substr(i, 2) == "go")
                i += 2;
        } else {
            cout << s[i];

            i++;
        }
    }
}