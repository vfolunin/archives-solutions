#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string toRoman(int n) {
    static const vector<pair<string, int>> CODES = {
        {"X", 10}, {"V", 5}, {"I", 1}
    };

    string res;
    for (auto &[code, value] : CODES) {
        while (n >= value) {
            n -= value;
            res += code;
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << toRoman(n);
}