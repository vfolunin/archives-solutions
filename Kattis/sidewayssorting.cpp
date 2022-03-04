#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toLower(string s) {
    for (char &c : s)
        c = tolower(c);
    return s;
}

bool compare(string &a, string &b) {
    return toLower(a) < toLower(b);
}

bool solve() {
    int h, w;
    cin >> h >> w;

    if (!h && !w)
        return 0;

    vector<string> a(w, string(h, ' '));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> a[j][i];

    sort(a.begin(), a.end(), compare);

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << a[j][i];
        cout << "\n";
    }

    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}