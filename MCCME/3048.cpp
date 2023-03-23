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
    getline(cin, s);

    for (int i = 0; i < s.size(); ) {
        if (i + 4 <= s.size() && s.substr(i, 4) == "rain") {
            cout << "sun";
            i += 4;
        } else {
            cout << s[i];
            i++;
        }
    }
}