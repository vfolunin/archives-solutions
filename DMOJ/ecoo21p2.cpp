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
    cin >> s;

    cout << s[0];
    for (int i = 1; i < s.size(); i++) {
        if (!((s[i - 1] == 'A') ^ (s[i] == 'A')))
            cout << " ";
        cout << s[i];
    }
}