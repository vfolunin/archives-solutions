#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getNext(string &s) {
    string res;
    for (int i = 0, j = 1; i < s.size(); i = j, j = i + 1) {
        while (j < s.size() && s[j - 1] == s[j])
            j++;
        res += to_string(j - i) + s[i];
        if (res.size() >= 1500)
            break;
    }
    return res;
}

bool solve() {
    string s;
    int n, index;
    cin >> s >> n >> index;

    if (!n && !index)
        return 0;

    for (int i = 0; i < n - 1; i++)
        s = getNext(s);

    cout << s[index - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}