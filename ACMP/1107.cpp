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
    int shuffleCount;
    cin >> s >> shuffleCount;

    for (int i = 0; i < shuffleCount; i++) {
        vector<string> a(2);
        for (int j = 0; j < s.size(); j++)
            a[j % 2].push_back(s[s.size() - 1 - j]);

        s = a[1] + a[0];
    }

    cout << s;
}