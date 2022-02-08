#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int count(string &text, string &pattern) {
    int from = 0, res = 0;
    while (1) {
        auto pos = text.find(pattern, from);
        if (pos == -1)
            break;
        from = pos + pattern.size();
        res++;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string text;
    cin >> text;

    int res = text.size();

    for (int len = 2; len < text.size(); len++) {
        for (int from = 0; from + len <= text.size(); from++) {
            string pattern = text.substr(from, len);
            res = min<int>(res, text.size() - (pattern.size() - 1) * count(text, pattern) + pattern.size());
        }
    }

    cout << res;
}