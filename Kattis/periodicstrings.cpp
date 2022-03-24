#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isPeriodic(string &s, int p) {
    if (s.size() % p)
        return 0;

    for (int i = p; i < s.size(); i += p) {
        string prevPart = s.substr(i - p, p);
        rotate(prevPart.begin(), prevPart.begin() + p - 1, prevPart.end());
        if (prevPart != s.substr(i, p))
            return 0;
    }

    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    int p = 1;
    while (!isPeriodic(s, p))
        p++;

    cout << p;
}