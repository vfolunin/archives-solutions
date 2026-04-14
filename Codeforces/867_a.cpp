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

    int sf = 0, fs = 0;
    for (int i = 0; i + 1 < s.size(); i++) {
        sf += s[i] == 'S' && s[i + 1] == 'F';
        fs += s[i] == 'F' && s[i + 1] == 'S';
    }

    cout << (sf > fs ? "YES" : "NO");
}