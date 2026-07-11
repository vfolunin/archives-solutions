#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    string s;
    cin >> s;

    int res = 0;
    for (char c : s)
        if (isdigit(c))
            res = res * 10 + c - '0';
    return res;
}

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    int res = 0;
    for (int i = 0; i < size; i++)
        res += read();

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}