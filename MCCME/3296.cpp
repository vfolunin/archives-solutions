#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int l = 0, r = 1;

    for (char c : s) {
        int nextL = l + (c != 'R');
        int nextR = r + (c != 'L');

        l = min(nextL, nextR + 1);
        r = min(nextR, nextL + 1);
    }

    cout << r;
}