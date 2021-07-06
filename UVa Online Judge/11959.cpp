#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rotate(string &s, int a, int b, int c, int d) {
    char t = s[a];
    s[a] = s[b];
    s[b] = s[c];
    s[c] = s[d];
    s[d] = t;
}

void rotate1(string &s) {
    rotate(s, 2, 3, 4, 5);
}

void rotate2(string &s) {
    rotate(s, 0, 4, 1, 2);
}

void rotate3(string &s) {
    rotate(s, 0, 3, 1, 5);
}

bool check(string &a, string &b) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (a == b)
                    return 1;
                rotate1(a);
            }
            rotate2(a);
        }
        rotate3(a);
    }
    return 0;
}

void solve() {
    string a, b;
    cin >> a >> b;

    cout << (check(a, b) ? "Equal\n" : "Not Equal\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}