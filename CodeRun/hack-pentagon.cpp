#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int ask(const string &s) {
    cout << s << endl;

    int res;
    cin >> res;

    if (!res)
        exit(0);

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string cur(n, 'a'), res = cur;
    int a = ask(cur);

    map<int, char> deltas;
    for (char c = 'a'; c <= 'z'; c++)
        deltas[abs(c - 'z') - abs(c - 'a')] = c;

    for (int i = 0; i < n; i++) {
        cur[i] = 'z';
        res[i] = deltas[ask(cur) - a];
        cur[i] = 'a';
    }

    ask(res);
}