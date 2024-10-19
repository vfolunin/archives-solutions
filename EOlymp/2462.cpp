#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> zFunction(const string &s) {
    vector<int> z(s.size());

    int blockL = 0, blockR = 0;
    for (int i = 1; i < s.size(); i++) {
        int blockLen = 0;

        if (i <= blockR)
            blockLen = min(z[i - blockL], blockR - i + 1);

        while (i + blockLen < s.size() && s[i + blockLen] == s[blockLen])
            blockLen++;

        z[i] = blockLen;

        if (blockR < i + blockLen - 1) {
            blockL = i;
            blockR = i + blockLen - 1;
        }
    }

    return z;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string pattern, text;
    cin >> pattern >> text;

    vector<int> zl = zFunction(pattern + "#" + text);
    zl.erase(zl.begin(), zl.begin() + pattern.size() + 1);

    reverse(pattern.begin(), pattern.end());
    reverse(text.begin(), text.end());

    vector<int> zr = zFunction(pattern + "#" + text);
    zr.erase(zr.begin(), zr.begin() + pattern.size() + 1);
    reverse(zr.begin(), zr.end());

    vector<int> res;
    for (int l = 0, r = pattern.size() - 1; r < text.size(); l++, r++)
        if (zl[l] + zr[r] >= pattern.size() - 1)
            res.push_back(l);

    cout << res.size() << "\n";
    for (int value : res)
        cout << value + 1 << " ";
}