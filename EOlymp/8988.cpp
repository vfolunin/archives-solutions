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
        if (s.substr(i, 2) == "ab") {
            cout << "ups";
            i += 2;
        } else {
            cout << s[i];
            i++;
        }
    }
}