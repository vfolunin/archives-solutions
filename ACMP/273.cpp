#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    unordered_set<int> res;
    for (int a = 0; a < s.size(); a++)
        for (int b = a + 1; b < s.size(); b++)
            for (int c = b + 1; c < s.size(); c++)
                if (s[a] != '0')
                    res.insert((s[a] - '0') * 100 + (s[b] - '0') * 10 + s[c] - '0');

    cout << res.size();
}