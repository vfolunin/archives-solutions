#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void rec(int step, int n, int k, string &s) {
    if (step == n) {
        cout << s << "\n";
        return;
    }

    static string digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    for (int i = k - 1; i >= 0; i--) {
        s.push_back(digits[i]);
        rec(step + 1, n, k, s);
        s.pop_back();
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    string s;
    rec(0, n, k, s);
}