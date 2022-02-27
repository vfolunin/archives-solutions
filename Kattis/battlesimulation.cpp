#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool combo(string s) {
    sort(s.begin(), s.end());
    return s == "HKS";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string moves;
    cin >> moves;

    string res;
    for (char move : moves) {
        if (move == 'R')
            res += 'S';
        else if (move == 'B')
            res += 'K';
        else
            res += 'H';

        if (res.size() >= 3 && combo(res.substr(res.size() - 3, 3))) {
            res.pop_back();
            res.pop_back();
            res.back() = 'C';
        }
    }

    cout << res;
}