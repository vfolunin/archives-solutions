#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int h;
    cin >> h;
    cin.ignore();

    if (!h)
        return 0;

    vector<string> a(h);
    int w = 0;
    for (string &s : a) {
        getline(cin, s);
        w = max<int>(w, s.size());
    }

    for (string &s : a)
        s.resize(w, ' ');

    vector<string> res(w, string(h, ' '));
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x] == '-' || a[y][x] == '|')
                res[x][h - 1 - y] = '-' + '|' - a[y][x];
            else
                res[x][h - 1 - y] = a[y][x];
        }
    }

    if (test)
        cout << "\n";
    for (string &s : res) {
        while (s.back() == ' ')
            s.pop_back();
        cout << s << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; solve(i); i++);
}