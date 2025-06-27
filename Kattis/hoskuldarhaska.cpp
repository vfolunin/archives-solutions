#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(vector<vector<string>> &a, int i, vector<string> &cur) {
    if (i == a.size()) {
        for (int j = 0; j < cur.size(); j++)
            cout << cur[j] << (j + 1 < cur.size() ? " " : "\n");
        return;
    }

    for (string &s : a[i]) {
        cur.push_back(s);
        rec(a, i + 1, cur);
        cur.pop_back();
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    vector<vector<string>> a(size);
    for (vector<string> &a : a) {
        int count;
        cin >> count;

        a.resize(count);
        for (string &s : a)
            cin >> s;

        sort(a.begin(), a.end());
    }

    vector<string> cur;
    rec(a, 0, cur);
}