#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long joseph2(long long size) {
    if (size == 1)
        return 1;
    else if (size % 2)
        return joseph2(size / 2) * 2 + 1;
    else
        return joseph2(size / 2) * 2 - 1;
}

bool solve() {
    string s;
    cin >> s;

    if (s == "00e0")
        return 0;

    cout << joseph2(stoll(s.substr(0, 2) + string(s.back() - '0', '0'))) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}