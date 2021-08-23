#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    string a, b;
    vector<int> used;

    Solver(string &a) : a(a), b(a.size(), ' '), used(10) {}

    void fillWithDecreasing(int from) {
        for (int pos = from, digit = 9; pos < b.size(); digit--)
            for (int usageCount = used[digit]; pos < b.size() && usageCount < 2; pos++, usageCount++)
                b[pos] = digit + '0';
    }

    bool rec(int pos) {
        if (pos == a.size())
            return 1;

        if (used[a[pos] - '0'] < 2) {
            b[pos] = a[pos];
            used[a[pos] - '0']++;
            if (rec(pos + 1))
                return 1;
            used[a[pos] - '0']--;
        }

        int digit = a[pos] - '0' - 1;
        while (digit >= 0 && used[digit] == 2)
            digit--;

        if (digit == -1)
            return 0;

        b[pos] = digit + '0';
        if (pos || digit)
            used[digit]++;

        fillWithDecreasing(pos + 1);
        return 1;        
    }

    string getRes() {
        rec(0);
        string res = b;
        reverse(res.begin(), res.end());
        while (res.size() > 1 && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    cout << Solver(s).getRes() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}