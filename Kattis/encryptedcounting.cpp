#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string getNext(string &s) {
    vector<pair<int, char>> parts;
    for (char c : s) {
        if (parts.empty() || parts.back().second != c)
            parts.push_back({ 1, c });
        else
            parts.back().first++;
    }

    string res;
    for (auto &[count, c] : parts)
        res += to_string(count) + c;
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a >> b;

    int res = 0;
    while (a != b) {
        a = getNext(a);
        res++;
    }

    cout << res;
}